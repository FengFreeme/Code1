#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <istream>
#include <sstream>
#include <algorithm>

using namespace std;

class QueryResult;		// 定义函数query的返回类型，这个定义是必须的
// 创建对象 读取输入文件 考虑与QueryResult对象共享数据的需求 
// 共享保存输入文件的vector和保存单词关联的行号 的set
class TextQuery
{
public:
	// vector<string>::size_type 是 vector<string> 类型的 size_type 成员
	// 它是一个无符号整数类型，用于表示向量的大小（即元素数量）。
	using line_no = vector<string>::size_type;
	TextQuery(istream&);
	QueryResult query(const string&) const;
private:
	// 输入文件
	shared_ptr<vector<string>> file;
	// 每个单词到它所在的行号的集合的映射
	// line_no 行号
	map<string, shared_ptr<set<line_no>>> wm;
};
// new vector<string> 分配指向 vector<string> 的指针
TextQuery::TextQuery(istream& is) : file(new vector<string>)
{
	string text;
	while (getline(is, text))			// 对文件中每一行
	{
		file->push_back(text);			// 当前行号
		int n = file->size() - 1;
		istringstream line(text);		// 将行文本分解为单词
		string word;
		while (line >> word)
		{
			// 如果单词不在wm中，以之为下标在wm中添加一项
			auto& lines = wm[word];
			if (!lines)								// 第一次遇到这个单词时，此指针为空
				// 创建一个新的 set<line_no> 对象，并将其所有权交给 lines 这个智能指针
				// 调用 reset 更新 lines 引用的 shared_ptr，使其指向这个新分配的 set
				lines.reset(new set<line_no>);		// 分配一个新的set
			lines->insert(n);
		}
	}
}

class QueryResult
{
	friend ostream& print(ostream&, const QueryResult&);
public:
	using line_no = vector<string>::size_type;
	QueryResult(string s, shared_ptr<set<line_no>> p, shared_ptr<vector<string>> f) : sought(s), lines(p), file(f) {}
	set<line_no>::iterator begin()
	{
		return lines->begin();
	}
	set<line_no>::iterator end()
	{
		return lines->end();
	}
	shared_ptr<vector<string>> get_file()
	{
		return file;
	}
private:
	string sought;		// 查询单词
	shared_ptr<set<line_no>> lines;		// 出现的行号
	shared_ptr<vector<string>> file;	// 输入文件
};

QueryResult TextQuery::query(const string& sought) const
{
	// 未找到sought 返回一个指向此set的指针
	static shared_ptr<set<line_no>> nodata(new set<line_no>);
	// 使用find查找单词而不是下标运算符 避免将单词添加到 wm 中
	auto loc = wm.find(sought);
	if (loc == wm.end())
		return QueryResult(sought, nodata, file);		// 未找到
	else
		return QueryResult(sought, loc->second, file);
}

ostream& print(ostream& os, const QueryResult& qr)
{
	// 如果找到了单词，打印出现次数和所有出现的位置
	// make_plural 用于根据输入的计数器（通常是一个表示数量的变量）将单词转换为单数或复数形式
	os << qr.sought << " occurs " << qr.lines->size() << " "
		<< "times" << endl;
	// 打印单词出现的每一行
	for (auto num : *qr.lines)
		// 避免行号从 0 开始给用户带来的困惑
		os << "\t(line " << num + 1 << ")" << *(qr.file->begin() + num) << endl;
	return os;
}
// 例子
// Query q = Query("fiery") & Query("bird") | Query("wind");

// 抽象基类 具体的查询类型从中派生
class Query_base
{
	friend class Query;
protected:
	using line_no = TextQuery::line_no;
	virtual ~Query_base() = default;
private:
	// eval 返回与当前Query匹配的QueryResult
	virtual QueryResult eval(const TextQuery&) const = 0;
	// rep 是表示查询的一个string
	virtual string rep() const = 0;
};
// WordQuery 保存要查找的单词（实际执行查询的唯一一个操作）!!!
class WordQuery :public Query_base
{
	friend class Query;
	WordQuery(const string& s) :query_word(s) {}
	QueryResult eval(const TextQuery& t) const
	{
		return t.query(query_word);
	}
	string rep() const
	{
		return query_word;
	}
	string query_word;
};

// Query 类对外提供接口，同时隐藏了 Query_base 的继承体系
// 每个Query对象都含有一个指向 Query_base 对象的shared_ptr
class Query
{
	friend Query operator~(const Query&);
	friend Query operator|(const Query&, const Query&);
	friend Query operator&(const Query&, const Query&);
public:
	// 创建一个新的WordQuery 那么这个指针会指向 WordQuery 
	Query(const string& s) :q(new WordQuery(s)) {}		
	// 接口函数：调用对应的 Query_base 操作
	QueryResult eval(const TextQuery& t) const
	{
		// 虚函数 实际调用 WordQuery 覆盖的 eval 和 rep 函数
		return q->eval(t);
	}
	string rep() const
	{
		return q->rep();
	}
private:
	// 私有的构造函数 定义一个 Query_base 对象
	// Query 操作使用它的 Query_base 指针来调用各自的 Query_base 虚函数
	Query(shared_ptr<Query_base> query) : q(query) {}
	shared_ptr<Query_base> q;
};
// 输出流引用
ostream& operator<<(ostream& os, const Query& query)
{
	return os << query.rep();
}

class NotQuery :public Query_base
{
	friend Query operator~(const Query&);
	NotQuery(const Query& q):query(q) {}
	string rep() const
	{
		return "~(" + query.rep() + ")";
	}
	QueryResult eval(const TextQuery&) const;
	Query query;
};

inline Query operator~(const Query& operand)
{
	// Query 里面的 Query_base 智能指针指向 NotQuery
	// 使用 ~ 右边的操作数 来初始化 NotQuery 对象 并返回 然后调用 eval 函数
	return Query(shared_ptr<Query_base>(new NotQuery(operand)));
}

class BinaryQuery :public Query_base
{
protected:
	BinaryQuery(const Query& l, const Query& r, string s) :lhs(l), rhs(r), opSym(s) {}
	// 抽象类：BinaryQuery 不定义eval
	string rep() const
	{
		return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")";
	}
	Query lhs, rhs;
	string opSym;		// 运算符名字
};

class AndQuery :public BinaryQuery
{
	friend Query operator&(const Query&, const Query&);
	AndQuery(const Query& left, const Query& right) :BinaryQuery(left, right, "&") {}
	// 具体的类：AndQuery 继承了 rep 并且定义了其他纯虚函数
	QueryResult eval(const TextQuery&) const;
};

inline Query operator&(const Query& lhs, const Query& rhs)
{
	// 使用 & 两边的操作数 来初始化 AndQuery 对象 并返回 然后调用 eval 函数
	return Query(shared_ptr<Query_base>(new AndQuery(lhs, rhs)));
}

class OrQuery :public BinaryQuery
{
	friend Query operator|(const Query&, const Query&);
	OrQuery(const Query& left, const Query& right) :BinaryQuery(left, right, "|") {}
	// 具体的类：AndQuery 继承了 rep 并且定义了其他纯虚函数
	QueryResult eval(const TextQuery&) const;
};

inline Query operator|(const Query& lhs, const Query& rhs)
{
	// 使用 | 两边的操作数 来初始化 OrQuery 对象 并返回 然后调用 eval 函数
	return Query(shared_ptr<Query_base>(new OrQuery(lhs, rhs)));
}

QueryResult OrQuery::eval(const TextQuery& text) const
{
	// 通过 Query 成员 lhs 和 rhs进行的虚调用
	// 调用 eval 返回每个运算对象的QueryResult
	auto left = lhs.eval(text), right = rhs.eval(text);
	auto ret_lines = make_shared<set<line_no>>(left.begin(), left.end());
	ret_lines->insert(right.begin(), right.end());
	return QueryResult(rep(), ret_lines, left.get_file());
}

QueryResult AndQuery::eval(const TextQuery& text) const
{
	// 通过 Query 成员 lhs 和 rhs进行的虚调用
	// 调用 eval 返回每个运算对象的QueryResult
	auto right = rhs.eval(text), left = lhs.eval(text);
	auto ret_lines = make_shared<set<line_no>>();
	// 将两个范围的交集写入一个目的迭代器中
	// 本次调用的目的迭代器项 ret 添加元素
	set_intersection(left.begin(), left.end(),
		right.begin(), right.end(),
		inserter(*ret_lines, ret_lines->begin()));
	return QueryResult(rep(), ret_lines, left.get_file());
}

QueryResult NotQuery::eval(const TextQuery& text) const
{
	// 通过 Query 运算对象对 eval 进行虚调用
	auto result = query.eval(text);
	auto ret_lines = make_shared<set<line_no>>();
	auto beg = result.begin(), end = result.end();
	// 对于输入文件的每一行，如果该行不在 result 中，则将其添加到 ret_lines
	auto sz = result.get_file()->size();
	for (size_t n = 0; n != sz; ++n)
	{
		// 检查当前行是否存在
		// *beg != n 行号不重复 
		if (beg == end || *beg != n)
			ret_lines->insert(n);
		else if (beg != end)
			++beg;
	}
	return QueryResult(rep(), ret_lines, result.get_file());
}

int main() {
	// 示例输入文本（模拟文件内容）
	string input_text =
		"Alice has a cat\n"
		"Bob has a dog\n"
		"The cat and dog are friends\n"
		"They play together\n";
	istringstream iss(input_text); // 将字符串转为输入流

	// 创建TextQuery对象并处理输入
	TextQuery tq(iss);

	// 示例1：查找包含"cat"或"dog"的行（使用或操作）
	Query q_or = Query("cat") | Query("dog");
	QueryResult result_or = q_or.eval(tq);
	cout << "Query: cat | dog\n";
	print(cout, result_or); // 输出匹配行

	// 示例2：查找包含"has"且不包含"Bob"的行（与操作和非操作）
	Query q_and_not = Query("has") & ~Query("Bob");
	cout << "\nQuery: has & ~Bob\n";
	print(cout, q_and_not.eval(tq));

	// 示例3：复杂查询（(cat & dog) | play）
	Query q_complex = (Query("cat") & Query("dog")) | Query("play");
	cout << "\nQuery: (cat & dog) | play\n";
	print(cout, q_complex.eval(tq));

	return 0;
}
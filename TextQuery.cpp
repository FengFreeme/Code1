#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <istream>
#include <sstream>
#include <algorithm>

using namespace std;

class QueryResult;		// ���庯��query�ķ������ͣ���������Ǳ����
// �������� ��ȡ�����ļ� ������QueryResult���������ݵ����� 
// �����������ļ���vector�ͱ��浥�ʹ������к� ��set
class TextQuery
{
public:
	// vector<string>::size_type �� vector<string> ���͵� size_type ��Ա
	// ����һ���޷����������ͣ����ڱ�ʾ�����Ĵ�С����Ԫ����������
	using line_no = vector<string>::size_type;
	TextQuery(istream&);
	QueryResult query(const string&) const;
private:
	// �����ļ�
	shared_ptr<vector<string>> file;
	// ÿ�����ʵ������ڵ��кŵļ��ϵ�ӳ��
	// line_no �к�
	map<string, shared_ptr<set<line_no>>> wm;
};
// new vector<string> ����ָ�� vector<string> ��ָ��
TextQuery::TextQuery(istream& is) : file(new vector<string>)
{
	string text;
	while (getline(is, text))			// ���ļ���ÿһ��
	{
		file->push_back(text);			// ��ǰ�к�
		int n = file->size() - 1;
		istringstream line(text);		// �����ı��ֽ�Ϊ����
		string word;
		while (line >> word)
		{
			// ������ʲ���wm�У���֮Ϊ�±���wm�����һ��
			auto& lines = wm[word];
			if (!lines)								// ��һ�������������ʱ����ָ��Ϊ��
				// ����һ���µ� set<line_no> ���󣬲���������Ȩ���� lines �������ָ��
				// ���� reset ���� lines ���õ� shared_ptr��ʹ��ָ������·���� set
				lines.reset(new set<line_no>);		// ����һ���µ�set
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
	string sought;		// ��ѯ����
	shared_ptr<set<line_no>> lines;		// ���ֵ��к�
	shared_ptr<vector<string>> file;	// �����ļ�
};

QueryResult TextQuery::query(const string& sought) const
{
	// δ�ҵ�sought ����һ��ָ���set��ָ��
	static shared_ptr<set<line_no>> nodata(new set<line_no>);
	// ʹ��find���ҵ��ʶ������±������ ���⽫������ӵ� wm ��
	auto loc = wm.find(sought);
	if (loc == wm.end())
		return QueryResult(sought, nodata, file);		// δ�ҵ�
	else
		return QueryResult(sought, loc->second, file);
}

ostream& print(ostream& os, const QueryResult& qr)
{
	// ����ҵ��˵��ʣ���ӡ���ִ��������г��ֵ�λ��
	// make_plural ���ڸ�������ļ�������ͨ����һ����ʾ�����ı�����������ת��Ϊ����������ʽ
	os << qr.sought << " occurs " << qr.lines->size() << " "
		<< "times" << endl;
	// ��ӡ���ʳ��ֵ�ÿһ��
	for (auto num : *qr.lines)
		// �����кŴ� 0 ��ʼ���û�����������
		os << "\t(line " << num + 1 << ")" << *(qr.file->begin() + num) << endl;
	return os;
}
// ����
// Query q = Query("fiery") & Query("bird") | Query("wind");

// ������� ����Ĳ�ѯ���ʹ�������
class Query_base
{
	friend class Query;
protected:
	using line_no = TextQuery::line_no;
	virtual ~Query_base() = default;
private:
	// eval �����뵱ǰQueryƥ���QueryResult
	virtual QueryResult eval(const TextQuery&) const = 0;
	// rep �Ǳ�ʾ��ѯ��һ��string
	virtual string rep() const = 0;
};
// WordQuery ����Ҫ���ҵĵ��ʣ�ʵ��ִ�в�ѯ��Ψһһ��������!!!
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

// Query ������ṩ�ӿڣ�ͬʱ������ Query_base �ļ̳���ϵ
// ÿ��Query���󶼺���һ��ָ�� Query_base �����shared_ptr
class Query
{
	friend Query operator~(const Query&);
	friend Query operator|(const Query&, const Query&);
	friend Query operator&(const Query&, const Query&);
public:
	// ����һ���µ�WordQuery ��ô���ָ���ָ�� WordQuery 
	Query(const string& s) :q(new WordQuery(s)) {}		
	// �ӿں��������ö�Ӧ�� Query_base ����
	QueryResult eval(const TextQuery& t) const
	{
		// �麯�� ʵ�ʵ��� WordQuery ���ǵ� eval �� rep ����
		return q->eval(t);
	}
	string rep() const
	{
		return q->rep();
	}
private:
	// ˽�еĹ��캯�� ����һ�� Query_base ����
	// Query ����ʹ������ Query_base ָ�������ø��Ե� Query_base �麯��
	Query(shared_ptr<Query_base> query) : q(query) {}
	shared_ptr<Query_base> q;
};
// ���������
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
	// Query ����� Query_base ����ָ��ָ�� NotQuery
	// ʹ�� ~ �ұߵĲ����� ����ʼ�� NotQuery ���� ������ Ȼ����� eval ����
	return Query(shared_ptr<Query_base>(new NotQuery(operand)));
}

class BinaryQuery :public Query_base
{
protected:
	BinaryQuery(const Query& l, const Query& r, string s) :lhs(l), rhs(r), opSym(s) {}
	// �����ࣺBinaryQuery ������eval
	string rep() const
	{
		return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")";
	}
	Query lhs, rhs;
	string opSym;		// ���������
};

class AndQuery :public BinaryQuery
{
	friend Query operator&(const Query&, const Query&);
	AndQuery(const Query& left, const Query& right) :BinaryQuery(left, right, "&") {}
	// ������ࣺAndQuery �̳��� rep ���Ҷ������������麯��
	QueryResult eval(const TextQuery&) const;
};

inline Query operator&(const Query& lhs, const Query& rhs)
{
	// ʹ�� & ���ߵĲ����� ����ʼ�� AndQuery ���� ������ Ȼ����� eval ����
	return Query(shared_ptr<Query_base>(new AndQuery(lhs, rhs)));
}

class OrQuery :public BinaryQuery
{
	friend Query operator|(const Query&, const Query&);
	OrQuery(const Query& left, const Query& right) :BinaryQuery(left, right, "|") {}
	// ������ࣺAndQuery �̳��� rep ���Ҷ������������麯��
	QueryResult eval(const TextQuery&) const;
};

inline Query operator|(const Query& lhs, const Query& rhs)
{
	// ʹ�� | ���ߵĲ����� ����ʼ�� OrQuery ���� ������ Ȼ����� eval ����
	return Query(shared_ptr<Query_base>(new OrQuery(lhs, rhs)));
}

QueryResult OrQuery::eval(const TextQuery& text) const
{
	// ͨ�� Query ��Ա lhs �� rhs���е������
	// ���� eval ����ÿ����������QueryResult
	auto left = lhs.eval(text), right = rhs.eval(text);
	auto ret_lines = make_shared<set<line_no>>(left.begin(), left.end());
	ret_lines->insert(right.begin(), right.end());
	return QueryResult(rep(), ret_lines, left.get_file());
}

QueryResult AndQuery::eval(const TextQuery& text) const
{
	// ͨ�� Query ��Ա lhs �� rhs���е������
	// ���� eval ����ÿ����������QueryResult
	auto right = rhs.eval(text), left = lhs.eval(text);
	auto ret_lines = make_shared<set<line_no>>();
	// ��������Χ�Ľ���д��һ��Ŀ�ĵ�������
	// ���ε��õ�Ŀ�ĵ������� ret ���Ԫ��
	set_intersection(left.begin(), left.end(),
		right.begin(), right.end(),
		inserter(*ret_lines, ret_lines->begin()));
	return QueryResult(rep(), ret_lines, left.get_file());
}

QueryResult NotQuery::eval(const TextQuery& text) const
{
	// ͨ�� Query �������� eval ���������
	auto result = query.eval(text);
	auto ret_lines = make_shared<set<line_no>>();
	auto beg = result.begin(), end = result.end();
	// ���������ļ���ÿһ�У�������в��� result �У�������ӵ� ret_lines
	auto sz = result.get_file()->size();
	for (size_t n = 0; n != sz; ++n)
	{
		// ��鵱ǰ���Ƿ����
		// *beg != n �кŲ��ظ� 
		if (beg == end || *beg != n)
			ret_lines->insert(n);
		else if (beg != end)
			++beg;
	}
	return QueryResult(rep(), ret_lines, result.get_file());
}

int main() {
	// ʾ�������ı���ģ���ļ����ݣ�
	string input_text =
		"Alice has a cat\n"
		"Bob has a dog\n"
		"The cat and dog are friends\n"
		"They play together\n";
	istringstream iss(input_text); // ���ַ���תΪ������

	// ����TextQuery���󲢴�������
	TextQuery tq(iss);

	// ʾ��1�����Ұ���"cat"��"dog"���У�ʹ�û������
	Query q_or = Query("cat") | Query("dog");
	QueryResult result_or = q_or.eval(tq);
	cout << "Query: cat | dog\n";
	print(cout, result_or); // ���ƥ����

	// ʾ��2�����Ұ���"has"�Ҳ�����"Bob"���У�������ͷǲ�����
	Query q_and_not = Query("has") & ~Query("Bob");
	cout << "\nQuery: has & ~Bob\n";
	print(cout, q_and_not.eval(tq));

	// ʾ��3�����Ӳ�ѯ��(cat & dog) | play��
	Query q_complex = (Query("cat") & Query("dog")) | Query("play");
	cout << "\nQuery: (cat & dog) | play\n";
	print(cout, q_complex.eval(tq));

	return 0;
}
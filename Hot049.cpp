#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

namespace chenkai
{
    // 常量引用 不能通过引用修改绑定的变量的值
    bool isLower(const char& c1, const char& c2)
    {
        return c1 < c2;
    }
}

class Solution 
{
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        // <string, int> int 为相应的放置的数组下标
        unordered_map<string, int> umap;
        vector<vector<string>> ans;
        // 总时间复杂度 O(nklogk)
        for (int i = 0; i < strs.size(); ++i)                           // 循环时间复杂度 O(n)
        {
            string tmp_str = strs[i];
            sort(tmp_str.begin(), tmp_str.end(), chenkai::isLower);     // 设最长的字符串的长度为 k, 时间复杂度为 O(klogk)
            // 未找到 创建新的 vector<string> 并 将排序后的 string 和对应的下标放入 umap
            // 哈希表操作​​（查找/插入）：
            // 平均时间复杂度 O(1)
            // 哈希表存储排序后的字符串 假设设最长的字符串的长度为 k， 每个字符串独立 空间复杂度 为 O(nk)
            if (umap.find(tmp_str) == umap.end())
            {
                // 列表
                ans.push_back({ strs[i] });
                int index = ans.size() - 1;
                umap[tmp_str] = index;
            }
            // 找到
            else
            {
                int index = umap[tmp_str];
                ans[index].push_back(strs[i]);
            }
        }
        return ans;
    }
};

int main()
{
    Solution S;
    vector<string> strs = { "a"};

    S.groupAnagrams(strs);

    return 0;
}
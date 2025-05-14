#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <map>

using namespace std;
/*
// ûͨ�� �ڴ泬��
class Solution 
{
public:
    vector<string> path;
    vector<vector<string>> res;
    vector<string> findItinerary(vector<vector<string>>& tickets)
    {
        vector<bool> used(tickets.size(), false);
        path.push_back(string("JFK"));
        backtracking(tickets, string("JFK"), used);

        sort(res.begin(), res.end());

        return res[0];
    }
    // 1. ȷ���βκͷ�������
    void backtracking(vector<vector<string>>& tickets, const string& previous, vector<bool>& used)
    {
        // 2. ȷ����ֹ����
        if (path.size() == tickets.size() + 1)
        {
            res.push_back(path);
            return;
        }
        // 3. ȷ���ݹ�����
        for (int i = 0; i < tickets.size(); i++)
        {
            if (used[i] == true || tickets[i][0] != previous)
                continue;
            path.push_back(tickets[i][1]);
            used[i] = true;
            backtracking(tickets, tickets[i][1], used);
            used[i] = false;
            path.pop_back();
        }
        return;
    }
};
*/
class Solution 
{
private:
    // unordered_map<����������map<����������������>> targets
    unordered_map<string, map<string, int>> targets;
    bool backtracking(int ticketNum, vector<string>& result)
    {
        if (result.size() == ticketNum + 1)
            return true;
        for (pair<const string, int>& target : targets[result.back()])
        {
            // ʣ�ຽ�д���
            if (target.second > 0)
            {
                result.push_back(target.first);
                target.second--;
                if (backtracking(ticketNum, result))
                    return true;
                result.pop_back();
                target.second++;
            }
        }
        return false;
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) 
    {
        vector<string> result;
        result.push_back(string("JFK"));
        for (const vector<string>& vec : tickets)
            targets[vec[0]][vec[1]]++;
        backtracking(tickets.size(), result);
        return result;
    }
    
};
int main()
{
    vector<vector<string>> tickets = {{"EZE", "AXA"}, {"TIA", "ANU"}, {"ANU", "JFK"}, {"JFK", "ANU"}, {"ANU", "EZE"}, {"TIA", "ANU"}, {"AXA", "TIA"}, {"TIA", "JFK"}, {"ANU", "TIA"}, {"JFK", "TIA"}};
    Solution S;
    S.findItinerary(tickets);

    return 0;
}
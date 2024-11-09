#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution 
{
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        if (intervals.size() <= 1)
            return intervals;
        sort(intervals.begin(), intervals.end(), compare);
        int right = intervals[0][1];;
        vector<vector<int>> ans;
        vector<int> interval;
        interval.push_back(intervals[0][0]);
        for (int i = 1; i < intervals.size(); ++i)
        {
            if (right >= intervals[i][0])
            {
                right = max(intervals[i][1], right);
            }
            else if (right < intervals[i][0])
            {
                interval.push_back(right);
                ans.push_back(interval);
                interval.clear();
                interval.push_back(intervals[i][0]);
                right = intervals[i][1];
            }
            if (i == intervals.size() - 1 && interval.size() == 1)
            {
                interval.push_back(right);
                ans.push_back(interval);
            }
        }
        return ans;
    }

    static bool compare(const vector<int>& interval1, const vector<int>& interval2)
    {
        if (interval1[0] != interval2[0])
            return interval1[0] < interval2[0];
        else
            return interval1[1] < interval2[1];
    }
};

int main()
{
    vector<vector<int>> intervals = { {1,3} ,{2,6},{8,10},{15,18} };
    Solution S;
    S.merge(intervals);

    return 0;
}
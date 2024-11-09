#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals)
    {
        sort(intervals.begin(), intervals.end(), compare);
        int ans = 0;
        int right = intervals[0][1];
        for (int i = 1; i < intervals.size(); ++i)
        {
            if (right > intervals[i][0])
            {
                ++ans;
                right = min(right, intervals[i][1]);
            }
            else
            {
                right = intervals[i][1];
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
    vector<vector<int>> intervals = {{ - 52,31 }, { -73, -26 }, { 82, 97 }, { -65, -11 }, { -62, -49 }, { 95, 99 }, { 58, 95 }, { -31, 49 }, { 66, 98 }, { -63, 2 }, { 30, 47 }, { -40, -26 }};

    Solution S;
    S.eraseOverlapIntervals(intervals);

    return 0;
}
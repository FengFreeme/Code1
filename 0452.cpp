#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int findMinArrowShots(vector<vector<int>>& points)
    {
        sort(points.begin(), points.end(), compare);
        int right = points[0][1];
        int ans = 1;
        for (int i = 1; i < points.size(); i++)
        {
            if (right >= points[i][0])
            {
                right = min(right, points[i][1]);
            }
            else if (right < points[i][0])
            {
                ++ans;
                right = points[i][1];
            }
        }
        return ans;
    }
    static bool compare(const vector<int>& point1, const vector<int>& point2)
    {
        if (point1[0] != point2[0])
            return point1[0] < point2[0];
        else
            return point1[1] < point2[1];
    }
};

int main()
{
    vector<vector<int>> points = { {3,9},{7,12},{3,8},{6,8},{9,10},{2,9},{0,9},{3,9},{0,6},{2,8} };
    Solution S;
    S.findMinArrowShots(points);

    return 0;
}
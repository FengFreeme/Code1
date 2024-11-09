#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
    {
        int curSum = 0;
        int min = INT_MAX;
        for (int i = 0; i < gas.size(); i++)
        {
            int rest = gas[i] - cost[i];
            curSum += rest;
            if (curSum < min)
                min = curSum;
        }
        if (curSum < 0)
            return -1;
        if (min >= 0)
            return 0;

        for (int i = gas.size() - 1; i >= 0; --i)
        {
            int rest = gas[i] - cost[i];
            min += rest;
            if (min >= 0)
                return i;
        }
        return -1;
    }
};

int main()
{
    vector<int> gas = { 3,3,4 }, cost = { 3,4,4 };
    Solution S;
    S.canCompleteCircuit(gas, cost);

    return 0;
}
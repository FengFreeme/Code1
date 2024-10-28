#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution 
{
public:
    bool isHappy(int n) 
    {
        if (n == 1)
            return true;

        unordered_set<int> uset;
        while (n != 1)
        {
            n = calculation(n);
            // 出现过，再次计算会循环，不会是快乐数
            if (uset.find(n) != uset.end())
                return false;
            else
                uset.insert(n);
        }
        return true;
    }

    int calculation(int n)
    {
        int sum = 0;
        while (n != 0)
        {
            int mod = n % 10;
            sum = sum + mod * mod;
            n = n / 10;
        }
        return sum;
    }
};
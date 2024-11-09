#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    int candy(vector<int>& ratings)
    {
        vector<int> candies(ratings.size(), 1);
        for (int i = 1; i < ratings.size(); ++i)
        {
            if (ratings[i] > ratings[i - 1])
                candies[i] = candies[i - 1] + 1;
        }
        for (int i = ratings.size() - 2; i >= 0; --i)
        {
            if (ratings[i] > ratings[i + 1])
                candies[i] = max(candies[i], candies[i + 1] + 1);
        }
        int candiesSum = 0;
        for (int i = 0; i < candies.size(); ++i)
        {
            candiesSum += candies[i];
        }
        return candiesSum;
    }
};

int main()
{
    vector<int> ratings = { 1,3,4,5,2 };

    Solution S;
    S.candy(ratings);

    return 0;
}
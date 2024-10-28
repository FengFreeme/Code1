#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution 
{
public:
    void reverseString(vector<char>& s) 
    {
        int size = s.size();
        int low = 0, high = size - 1;
        while (low < high)
        {
            char temp = s[low];
            s[low] = s[high];
            s[high] = temp;
            low++;
            high--;
        }
    }
};
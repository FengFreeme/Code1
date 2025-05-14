#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    int monotoneIncreasingDigits(int n)
    {
        if (n < 10)
            return n;
        while (n >= 0)
        {
            int num = n;
            int a = num % 10;
            num /= 10;
            // ��¼���жϵ�λ��
            int index = 1;
            while (num > 0)
            {
                int b = num % 10;
                if (a >= b)
                {
                    a = b;
                    num /= 10;
                    ++index;
                }
                else
                {
                    // �ӿ��������
                    n = num * pow(10, index);
                    break;
                }
            }
            if (num == 0)
                return n;
            --n;
        }
        return n;
    }
};

int main()
{
    Solution S;
    S.monotoneIncreasingDigits(213);

    return 0;
}
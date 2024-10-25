#include <iostream>
#include <vector>

using namespace std;
/*
// 直接循环
int main()
{
	int n;
	cin >> n;
	vector<int> array(n, 0);
	int num;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		array[i] = num;
	}
	int low, high;
	int sum;
	while (cin >> low >> high)
	{
		sum = 0;
		for (int i = low; i <= high; i++)
		{
			sum += array[i];
		}
		cout << sum << endl;
	}
	return 0;
}
*/
// 动态加减
int main()
{
	int n;
	cin >> n;
	vector<int> array(n, 0);
	int num;
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		sum += num;
		array[i] = sum;
	}
	int low, high;
	while (cin >> low >> high)
	{
		if (low == 0)
			cout << array[high] << endl;
		else if (low > 0)
			cout << array[high] - array[low - 1] << endl;
	}
	return 0;
}
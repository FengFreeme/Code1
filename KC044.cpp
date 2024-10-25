#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> rows(n, 0);
	vector<int> cols(m, 0);
	int num;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> num;
			rows[i] += num;
			cols[j] += num;
		}
	}
	for (int i = 1; i < n; i++)
	{
		rows[i] = rows[i] + rows[i - 1];
	}
	for (int j = 1; j < m; j++)
	{
		cols[j] = cols[j] + cols[j - 1];
	}
	int minDist = INT_MAX;
	for (int i = 0; i < n - 1; i++)
	{
		minDist = min(minDist, abs((rows[n - 1] - rows[i]) - rows[i]));
	}
	for (int j = 0; j < m - 1; j++)
	{
		minDist = min(minDist, abs((cols[m - 1] - cols[j]) - cols[j]));
	}
	cout << minDist << endl;

	return 0;
}
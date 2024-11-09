#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dir[4][2] = { 0, 1, 1, 0, 0, -1, -1, 0 };

void BFS(vector<vector<int>>& grid, int x, int y);

int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> grid(n, vector<int>(m, 0));
	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> grid[i][j];
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (grid[i][j] == 1)
			{
				++ans;
				BFS(grid, i, j);
			}
		}
	}
	cout << ans << endl;
	return 0;
}

void BFS(vector<vector<int>>& grid, int x, int y)
{
	queue<pair<int, int>> que;
	que.push({ x, y });
	grid[x][y] = 0;
	while (!que.empty())
	{
		auto point = que.front();
		que.pop();
		// grid[point.first][point.second] = 0;
		for (int i = 0; i < 4; ++i)
		{
			int dirx = point.first + dir[i][0];
			int diry = point.second + dir[i][1];
			if (dirx < 0 || dirx >= grid.size() || diry < 0 || diry >= grid[0].size() || grid[dirx][diry] != 1)
				continue;
			grid[dirx][diry] = 0;
			que.push({ dirx, diry });
		}
	}
	return;
}

#include <iostream>
#include <vector>	
#include <queue>
using namespace std;

int n, m;
vector<vector<int>> v;
vector<vector<bool>> visited;

void bfs(vector<pair<int, int>> start)
{
	queue<pair<int, int>> q;

	int dx[] = { 0,0,-1,1 };
	int dy[] = { -1,1,0,0 };

	int maxDepth = 0;

	for (int i = 0; i < start.size(); ++i)
	{
		q.push(start[i]);
		visited[start[i].first][start[i].second] = true;
	}

	while (!q.empty())
	{
		pair<int, int> pos = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int x = dx[i] + pos.second;
			int y = dy[i] + pos.first;

			if (x < 0 || x >= m || y < 0 || y >= n)
				continue;

			if (v[y][x] == -1)
				continue;

			if (visited[y][x])
				continue;

			visited[y][x] = true;
			v[y][x] = v[pos.first][pos.second] + 1;
			maxDepth = max(maxDepth, v[y][x]);
			q.push(make_pair(y, x));
		}
	}

	for (int i = 0; i < v.size(); ++i)
	{
		for (int j = 0; j < v[0].size(); ++j)
		{
			if (v[i][j] == 0)
			{
				cout << -1;
				return;
			}
		}
	}

	maxDepth = maxDepth > 0 ? maxDepth - 1 : maxDepth;
	cout << maxDepth;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> m >> n;

	v.resize(n, vector<int>(m));
	visited.resize(n, vector<bool>(m));
	vector<pair<int, int>> start;

	int value;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> value;

			v[i][j] = value;

			if (value == 1)
				start.push_back(make_pair(i, j));
		}
	}

	bfs(start);
}
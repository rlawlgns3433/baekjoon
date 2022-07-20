#include <iostream>
#include <vector>
#include <queue>
#define endl '\n'
#define fastio (ios::sync_with_stdio(0), cin.tie(0), cout.tie(0))
using namespace std;

vector<vector<int>> c_map;
vector<vector<bool>> visited;

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int n, m, k;

void bfs(int x, int y)
{
	queue<pair<int, int>> q;
	q.push({ x,y });
	visited[x][y] = true;

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

			if (c_map[nx][ny] == 0) continue;

			if (c_map[nx][ny] == 1 && visited[nx][ny] == false)
			{
				q.push({ nx, ny });
				visited[nx][ny] = true;
			}
		}
	}
}

void process()
{
	int bug = 0;

	cin >> m >> n >> k;

	c_map.resize(n, vector<int>(m, 0));
	visited.resize(n, vector<bool>(m, false));



	for (int i = 0; i < k; i++)
	{
		int x, y;
		cin >> y >> x;

		c_map[x][y] = 1;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (c_map[i][j] == 1 && visited[i][j] == false)
			{
				bug++;
				bfs(i, j);
			}
		}
	}
	cout << bug << endl;

	c_map.clear();
	visited.clear();
}

int main()
{
	fastio;
	int testcase;
	cin >> testcase;
	for (int i = 0; i < testcase; i++)
	{
		process();
	}
}
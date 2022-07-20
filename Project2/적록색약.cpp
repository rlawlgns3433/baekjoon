#include <iostream>
#include <queue>
#include <vector>
#define fastio (ios::sync_with_stdio(0), cin.tie(0), cout.tie(0))
using namespace std;

vector<vector<char>> c_map, cw_map;
vector<vector<bool>> visited, cw_visited;

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int n;

void bfs(int x, int y)
{
	queue<pair<int, int>> q;
	q.push({ x, y });
	visited[x][y] = true;
	char color = c_map[x][y];

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (c_map[nx][ny] != color || visited[nx][ny] == true) continue;
			if (c_map[nx][ny] == color && visited[nx][ny] == false)
			{
				visited[nx][ny] = true;
				q.push({ nx, ny });
			}
		}
	}
}

void cw_bfs(int x, int y)
{
	queue<pair<int, int>> q;
	q.push({ x, y });
	cw_visited[x][y] = true;
	char color = cw_map[x][y];

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (cw_map[nx][ny] != color || cw_visited[nx][ny] == true) continue;
			if (cw_map[nx][ny] == color && cw_visited[nx][ny] == false)
			{
				cw_visited[nx][ny] = true;
				q.push({ nx, ny });
			}
		}
	}
}

int main()
{
	int answer = 0;
	cin >> n;
	c_map.resize(n, vector<char>(n));
	visited.resize(n, vector<bool>(n, false));
	cw_map.resize(n, vector<char>(n));
	cw_visited.resize(n, vector<bool>(n, false));

	for (int i = 0; i < n; i++)
	{
		string str;
		cin.ignore();
		cin >> str;

		for (int j = 0; j < n; j++)
		{
			c_map[i][j] = str[j];
			if (str[j] == 'G')
				cw_map[i][j] = 'R';
			else cw_map[i][j] = str[j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			char color = c_map[i][j];
			if (c_map[i][j] == color && visited[i][j] == false)
			{
				answer++;
				bfs(i, j);
			}
		}
	}

	cout << answer << ' ';
	answer = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			char color = cw_map[i][j];
			if (cw_map[i][j] == color && cw_visited[i][j] == false)
			{
				answer++;
				cw_bfs(i, j);
			}
		}
	}
	cout << answer;
}
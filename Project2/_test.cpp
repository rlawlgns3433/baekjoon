// 연구소 진행중
#include <iostream>
#include <vector>
#define pii pair<int,int>
using namespace std;

int n, m, answer;
vector<vector<int>> coord, visited;
vector<pii> wall, virus;
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1 ,1 };

void dfs(int y, int x)
{
	for (int i = 0; i < 4; i++)
	{
		int ny = dy[i] + y;
		int nx = dx[i] + x;

		if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue; // 오버플로우 주의
		if (visited[ny][nx]) continue;
		if (coord[ny][nx] == 1) continue;
		visited[ny][nx] = 1;
		dfs(ny, nx);
	}
}

int solution()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			visited[i][j] = 0;
		}
	}

	for (pii p : virus)
	{
		visited[p.first][p.second] = 1;
		dfs(p.first, p.second);
	}

	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (coord[i][j] == 0) cnt++;
		}
	}
	return cnt;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	coord.resize(n, vector<int>(m));
	visited.resize(n, vector<int>(m));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> coord[i][j];
			if (coord[i][j] == 0) wall.push_back(make_pair(i, j));
			if (coord[i][j] == 2) virus.push_back(make_pair(i, j));
		}
	}
	int w_size = wall.size();

	for (int i = 0; i < w_size; i++)
	{
		for (int j = 0; j < i; j++)
		{
			for (int k = 0; k < j; k++)
			{
				// 벽 세우기
				coord[wall[i].first][wall[i].second] = 1;
				coord[wall[j].first][wall[j].second] = 1;
				coord[wall[k].first][wall[k].second] = 1;
				
				// 바이러스 퍼뜨리고 안전영역 찾기
				answer = max(answer, solution());

				// 되돌려 놓기
				coord[wall[i].first][wall[i].second] = 0;
				coord[wall[j].first][wall[j].second] = 0;
				coord[wall[k].first][wall[k].second] = 0;
			}
		}
	}
	cout << answer << endl;
}
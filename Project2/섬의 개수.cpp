#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef pair<int, int> pii;

vector<vector<int>> graph, visited;

int w, h;
int cnt;

int dx[] = { -1,-1,-1,0,0,0,1,1,1 };
int dy[] = { -1,0,1,-1,0,1,-1,0,1 };


int bfs(int x, int y)
{
	int c = 0;
	queue<pii> q;
	q.push({ x,y });

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 9; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;

			if (graph[nx][ny] == 0) continue; // graph[3][1]¿¡¼­ vector out of range 
			if (visited[nx][ny] == 1) continue;
			if (graph[nx][ny] == 1) {
				q.push({ nx,ny });
				visited[nx][ny] = 1;
				c = 1;
			}
		}
	}
	return c;
}

void testcase()
{

	cnt = 0;
	cin >> w >> h;

	if (w == 0 && h == 0) exit(0);

	graph.resize(h, vector<int>(w, 0));
	visited.resize(h, vector<int>(w, 0));

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			cin >> graph[i][j];
		}
	}
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (bfs(i, j) == 1)
				cnt++;
		}
	}

	cout << cnt << '\n';
	graph.clear();
	visited.clear();

}

int main()
{
	while (true)
	{
		testcase();
	}

}
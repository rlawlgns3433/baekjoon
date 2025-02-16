#include <iostream>
#include <vector>
#include <string>
#include <queue>
#define WALL 'W'
#define LAND 'L'
using namespace std;

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int n, m;

class Position
{
public:
	Position(int _y, int _x, char _value) : y(_y), x(_x), value(_value) { visited = false; count = 0; }

	int x, y;
	int count;
	char value;
	bool visited;

	void SetVisited(bool _visited = false)
	{
		visited = _visited;
	}
};

int Solution(const vector<vector<Position*>>& map, int startY, int startX)
{
	queue<Position*> q;
	q.push(map[startY][startX]);
	map[startY][startX]->SetVisited(true);

	int count = 1;
	while (!q.empty())
	{
		Position* front = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int x = front->x + dx[i];
			int y = front->y + dy[i];

			if (x < 0 || x >= m || y < 0 || y >= n)
				continue;

			if (map[y][x]->visited)
				continue;

			if (map[y][x]->value == WALL)
				continue;

			map[y][x]->SetVisited(true);
			map[y][x]->count = map[front->y][front->x]->count + 1;
			count = max(count, map[y][x]->count);
			q.push(map[y][x]);
		}
	}

	return count;
}

void ClearVisitedArray(const vector<vector<Position*>>& map)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			map[i][j]->SetVisited();
			map[i][j]->count = 0;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int answer = 0;
	cin >> n >> m;

	vector<vector<Position*>> map(n, vector<Position*>(m));

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			char value;
			cin >> value;
			Position* p = new Position(i, j, value);
			map[i][j] = p;
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (map[i][j]->value == WALL)
				continue;

			ClearVisitedArray(map);
			answer = max(answer, Solution(map, i, j));
		}
	}

	cout << answer;
}
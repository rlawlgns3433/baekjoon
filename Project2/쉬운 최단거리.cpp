#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

class Position
{
public:
	Position() { y = -1; x = -1; value = -1; depth = -1; }
	Position(int _y, int _x, int _value) : y(_y), x(_x), value(_value) { depth = 0; }
	int y, x, value, depth;
};

void Solution(const vector<vector<Position*>>& v, Position* start, vector<vector<bool>>& visited)
{
	queue<Position*> q;
	q.push(start);
	visited[start->y][start->x] = true;

	while (!q.empty())
	{
		Position* current = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int cx = current->x + dx[i];
			int cy = current->y + dy[i];

			if (cx < 0 || cy < 0 || cx >= m || cy >= n)
				continue;

			if (visited[cy][cx])
				continue;

			if (v[cy][cx]->value == 0)
				continue;

			v[cy][cx]->depth = current->depth + 1;
			visited[cy][cx] = true;
			q.push(v[cy][cx]);
		}
	}
}

void Print(const vector<vector<Position*>>& positions)
{
	for (auto& position : positions)
	{
		for (auto& e : position)
		{
			if (e->depth == 0 && e->value == 1)
				cout << "-1 ";
			else
				cout << e->depth << " ";
		}
		cout << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	vector<vector<Position*>> positions(n, vector<Position*>(m));
	vector<vector<bool>> visited(n, vector<bool>(m));

	Position* start = new Position();

	int value;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> value;
			Position* position = new Position(i, j, value);
			if (value == 2)
				start = position;

			positions[i][j] = position;
		}
	}

	Solution(positions, start, visited);
	Print(positions);
}
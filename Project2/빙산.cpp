#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int n, m;
vector<pair<int, int>> islands;

class Position
{
public:
	Position(int _y, int _x, int _value) : y(_y), x(_x), value(_value) {}
	void CalcAdjCount(vector<vector<Position*>>& v)
	{
		adjCount = 0;
		for (int i = 0; i < 4; ++i)
		{
			int cx = dx[i] + x;
			int cy = dy[i] + y;

			if (cx < 0 || cy < 0 || cx >= m || cy >= n)
				continue;

			if (v[cy][cx]->value == 0)
				adjCount++;
		}
	}

	void Melt()
	{
		value -= adjCount;

		if (value < 0)
			value = 0;
	}

	int value, y, x;
	bool visited = false;
	int adjCount = 0;
};

void ResetIslands(vector<vector<Position*>>& v)
{
	for (auto& e : islands)
		v[e.first][e.second]->visited = false;

	islands.clear();
}

void MeltIslands(vector<vector<Position*>>& v)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			v[i][j]->Melt();
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			v[i][j]->CalcAdjCount(v);
		}
	}
}

bool Solution(vector<vector<Position*>>& v, int startY, int startX)
{
	if (v[startY][startX]->value == 0 || v[startY][startX]->visited)
		return false;

	queue<Position*> q;
	q.push(v[startY][startX]);

	while (!q.empty())
	{
		auto current = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int cx = current->x + dx[i];
			int cy = current->y + dy[i];

			if (cx < 0 || cy < 0 || cx >= m || cy >= n)
				continue;

			if (v[cy][cx]->visited || v[cy][cx]->value == 0)
				continue;

			v[cy][cx]->visited = true;
			islands.push_back({ cy, cx });
			q.push(v[cy][cx]);
		}
	}

	return true;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	vector<vector<Position*>> positions(n, vector<Position*>(m));

	int value;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> value;
			Position* position = new Position(i, j, value);
			positions[i][j] = position;
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			positions[i][j]->CalcAdjCount(positions);
		}
	}

	int answer = 0;
	int day = 0;

	while (true)
	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if (Solution(positions, i, j))
					answer++;
			}
		}

		if (answer == 1)
		{
			ResetIslands(positions);
			MeltIslands(positions);
			answer = 0;
			day++;
		}
		else if (answer == 0)
			break;
		else
		{
			answer = day;
			break;
		}
	}


	cout << answer;
}
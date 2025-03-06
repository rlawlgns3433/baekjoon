#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

class Position
{
public:
	Position(int _y, int _x, int _value) : y(_y), x(_x), value(_value) { broken = 0; unbroken = 0; visited = false; }
	int y, x;
	int value;
	int broken;
	int unbroken;
	bool visited;
};

int Solution(vector<vector<Position*>>& v)
{
	queue<pair<int, Position*>> q;
	v[0][0]->visited = true;
	v[0][0]->unbroken = 1;
	q.push(make_pair(0, v[0][0]));

	while (!q.empty())
	{
		Position* currentPosition = q.front().second;
		int broken = q.front().first;
		q.pop();

		if (currentPosition->y == n - 1 && currentPosition->x == m - 1)
		{
			if (broken)
				return v[n - 1][m - 1]->broken;
			else
				return v[n - 1][m - 1]->unbroken;
		}

		for (int i = 0; i < 4; ++i)
		{
			int x = currentPosition->x + dx[i];
			int y = currentPosition->y + dy[i];

			if (x < 0 || y < 0 || x >= m || y >= n)
				continue;

			if (v[y][x]->visited && (v[y][x]->unbroken > 0 || v[y][x]->unbroken > 0))
				continue;

			if (v[y][x]->value == 1)
			{
				if (!broken)
				{
					v[y][x]->broken = v[currentPosition->y][currentPosition->x]->unbroken + 1;
					v[y][x]->visited = true;
					q.push(make_pair(1, v[y][x]));
				}
			}
			else if (v[y][x]->value == 0)
			{
				int brokenValue = v[y][x]->broken;

				if (broken == 1)
				{
					if (brokenValue)
						continue;

					v[y][x]->broken = v[currentPosition->y][currentPosition->x]->broken + 1;
				}
				else
				{
					v[y][x]->unbroken = v[currentPosition->y][currentPosition->x]->unbroken + 1;
				}

				v[y][x]->visited = true;
				q.push(make_pair(broken, v[y][x]));
			}
		}
	}

	return -1;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	vector<vector<Position*>> v(n, vector<Position*>(m));
	string val;
	int value;
	for (int i = 0; i < n; ++i)
	{
		cin >> val;

		for (int j = 0; j < m; ++j)
		{
			value = val[j] - '0';
			Position* position = new Position(i, j, value);
			v[i][j] = position;
		}
	}

	cout << Solution(v);
}
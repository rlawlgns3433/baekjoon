#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, k;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

class Position
{
public:
	Position(int _y, int _x) : y(_y), x(_x) { isColored = false; visited = false; }
	int y, x;
	bool isColored, visited;
};

void ColorPosition(int rangeX, int rangeY, int startX, int startY, vector<vector<Position*>>& positions)
{
	for (int i = startY; i < startY + rangeY; ++i)
	{
		for (int j = startX; j < startX + rangeX; ++j)
		{
			positions[i][j]->isColored = true;
		}
	}
}

int Solution(const vector<vector<Position*>>& positions, int startY, int startX)
{
	int count = 0;

	if (positions[startY][startX]->isColored || positions[startY][startX]->visited)
		return count;

	queue<Position*> q;
	q.push(positions[startY][startX]);
	positions[startY][startX]->visited = true;
	count++;

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

			if (positions[cy][cx]->isColored || positions[cy][cx]->visited)
				continue;

			count++;
			positions[cy][cx]->visited = true;
			q.push(positions[cy][cx]);
		}
	}

	return count;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> k;

	vector<vector<Position*>> positions(n, vector<Position*>(m));

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			Position* position = new Position(i, j);
			positions[i][j] = position;
		}
	}


	int leftX, leftY, rightX, rightY;
	for (int i = 0; i < k; ++i)
	{
		cin >> leftX >> leftY >> rightX >> rightY;

		int rangeX = rightX - leftX;
		int rangeY = rightY - leftY;

		ColorPosition(rangeX, rangeY, leftX, leftY, positions);
	}

	int answerCount = 0;
	vector<int> areas;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			int area = Solution(positions, i, j);
			if (area > 0)
			{
				areas.push_back(area);
				answerCount++;
			}
		}
	}

	sort(areas.begin(), areas.end());

	cout << answerCount << '\n';
	for (auto& area : areas)
		cout << area << " ";
}
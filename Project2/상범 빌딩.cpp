#include <iostream>
#include <vector>
#include <queue>
#define endl '\n'
using namespace std;

int z, y, x;

int dx[] = { 0,0,1,-1,0,0 };
int dy[] = { 1,-1,0,0,0,0 };
int dz[] = { 0,0,0,0,1,-1 };

class Position
{
public:
	Position(int _z, int _y, int _x, char _value) : z(_z), y(_y), x(_x), value(_value)
	{
		visited = false;
		moveCount = 0;
	}

	int z, y, x;
	int moveCount;
	char value;
	bool visited;
};

int Solution(vector<vector<vector<Position*>>>& positions, Position* start, Position* end)
{
	queue<Position*> q;
	q.push(start);

	start->visited = true;

	while (!q.empty())
	{
		Position* current = q.front();
		q.pop();

		if (current == end)
			return current->moveCount;

		for (int i = 0; i < 6; ++i)
		{
			int cx = dx[i] + current->x;
			int cy = dy[i] + current->y;
			int cz = dz[i] + current->z;

			if (cx < 0 || cy < 0 || cz < 0 || cx >= x || cy >= y || cz >= z)
				continue;

			if (positions[cz][cy][cx]->visited)
				continue;

			if (positions[cz][cy][cx]->value == '#')
				continue;

			positions[cz][cy][cx]->moveCount = current->moveCount + 1;
			positions[cz][cy][cx]->visited = true;
			q.push(positions[cz][cy][cx]);
		}
	}

	return 0;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	Position* start = nullptr;
	Position* end = nullptr;
	while (true)
	{
		cin >> z >> y >> x;

		if (z == 0 && y == 0 && x == 0)
			break;

		vector<vector<vector<Position*>>> positions(z, vector<vector<Position*>>(y, vector<Position*>(x)));

		string row;

		for (int i = 0; i < z; ++i)
		{
			for (int j = 0; j < y; ++j)
			{
				cin >> row;
				for (int k = 0; k < x; ++k)
				{
					Position* position = new Position(i, j, k, row[k]);
					positions[i][j][k] = position;

					if (row[k] == 'S')
						start = position;
					else if (row[k] == 'E')
						end = position;
				}
			}
		}
		int answer = Solution(positions, start, end);
		if (answer > 0)
			cout << "Escaped in " << answer << " minute(s)." << endl;
		else
			cout << "Trapped!" << endl;
	}
}
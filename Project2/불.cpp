#include <iostream>
#include <vector>
#include <queue>
#define BLANK '.'
#define WALL '#'
#define SANGEUN '@'
#define FIRE '*'
using namespace std;

class Position
{
public:
	Position(int _y, int _x, char _value) : y(_y), x(_x), value(_value) {}
	int x, y;
	char value;
};

bool MoveCharacter(queue<Position*>& posQ, vector<vector<Position*>>& map, int& w, int& h, int& answer, bool& escape)
{
	int dx[] = { 0,0,-1,1 };
	int dy[] = { -1,1,0,0 };
	bool move = false;

	int size = posQ.size();
	for (int c = 0; c < size; ++c)
	{
		Position* currentPosition = posQ.front();
		posQ.pop();

		for (int i = 0; i < 4; ++i)
		{
			int x = dx[i] + currentPosition->x;
			int y = dy[i] + currentPosition->y;

			if (x < 0 || y < 0 || x >= w || y >= h)
			{
				answer++;
				escape = true;
				move = true;
				return move;
			}

			if (map[y][x]->value != BLANK)
				continue;

			move = true;
			map[y][x]->value = SANGEUN;
			posQ.push(map[y][x]);
		}
	}

	if (move)
	{
		answer++;
		return move;
	}
	else
		return move;
}

void MoveFire(queue<Position*>& fireQ, vector<vector<Position*>>& map, int& w, int& h)
{
	int dx[] = { 0,0,-1,1 };
	int dy[] = { -1,1,0,0 };
	bool move = false;

	int size = fireQ.size();

	for (int c = 0; c < size; ++c)
	{
		Position* currentPosition = fireQ.front();
		fireQ.pop();

		for (int i = 0; i < 4; ++i)
		{
			int x = dx[i] + currentPosition->x;
			int y = dy[i] + currentPosition->y;

			if (x < 0 || y < 0 || x >= w || y >= h)
				continue;

			if (map[y][x]->value == FIRE || map[y][x]->value == WALL)
				continue;

			move = true;
			map[y][x]->value = FIRE;
			fireQ.push(map[y][x]);
		}
	}
}

void Solution(vector<vector<Position*>> map, int w, int h, queue<Position*> _fireQ, Position* startPos)
{
	int dx[] = { 0,0,-1,1 };
	int dy[] = { -1,1,0,0 };

	queue<Position*> posQ;
	queue<Position*> fireQ = _fireQ;
	posQ.push(startPos);

	int answer = 0;
	bool escape = false;

	while (!escape)
	{
		MoveFire(fireQ, map, w, h);
		bool move = MoveCharacter(posQ, map, w, h, answer, escape);

		if (escape)
		{
			cout << answer << '\n';
			return;
		}

		if (!move)
		{
			cout << "IMPOSSIBLE\n";
			return;
		}
	}
}

void Testcase()
{
	int w, h;
	cin >> w >> h;

	vector<vector<Position*>> map(h, vector<Position*>(w));
	Position* startPos = nullptr;
	queue<Position*> fireQ;
	for (int i = 0; i < h; ++i)
	{
		for (int j = 0; j < w; ++j)
		{
			char value;
			cin >> value;
			Position* position = new Position(i, j, value);

			if (value == SANGEUN)
				startPos = position;
			else if (value == FIRE)
				fireQ.push(position);

			map[i][j] = position;
		}
	}

	Solution(map, w, h, fireQ, startPos);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int testcase;

	cin >> testcase;

	for (int i = 0; i < testcase; ++i)
	{
		Testcase();
	}

	return 0;
}
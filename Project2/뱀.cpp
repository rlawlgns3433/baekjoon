#include <iostream>
#include <deque>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

enum class Direction
{
	up = 1,
	right = 2,
	down = 3,
	left = 4,
};

int totalTime = 0;
int n = 0;
int appleCount = 0;
int rotationCount = 0;
vector<vector<int>> gameMap;
map<int, Direction> rotations;

class Snake
{
public:

	deque<pair<int, int>> snake;
	Direction direction;

	Snake()
	{
		direction = Direction::right;
		snake.push_back(make_pair(1, 1));
	}

	bool Move()
	{
		pair<int, int> next;
		switch (direction)
		{
		case Direction::up:
			if (snake.back().second - 1 == 0)
				return false;
			next = make_pair(snake.back().first, snake.back().second - 1);
			if (find(snake.begin(), snake.end(), next) != snake.end())
				return false;

			snake.push_back(next);
			totalTime++;
			break;
		case Direction::right:
			if (snake.back().first == n)
				return false;
			next = make_pair(snake.back().first + 1, snake.back().second);
			if (find(snake.begin(), snake.end(), next) != snake.end())
				return false;

			snake.push_back(next);
			totalTime++;
			break;
		case Direction::down:
			if (snake.back().second == n)
				return false;
			next = make_pair(snake.back().first, snake.back().second + 1);
			if (find(snake.begin(), snake.end(), next) != snake.end())
				return false;

			snake.push_back(next);
			totalTime++;
			break;
		case Direction::left:
			if (snake.back().first - 1 == 0)
				return false;

			next = make_pair(snake.back().first - 1, snake.back().second);
			if (find(snake.begin(), snake.end(), next) != snake.end())
				return false;

			snake.push_back(next);
			totalTime++;
			break;
		}

		if (gameMap[snake.back().second][snake.back().first] == 0)
			snake.pop_front();
		else
			gameMap[snake.back().second][snake.back().first] = 0;

		return true;
	}

	void SetDirection(Direction _direction)
	{
		switch (direction)
		{
		case Direction::up:
			direction = _direction;
			break;
		case Direction::right:
			if (_direction == Direction::left)
				direction = Direction::up;
			else
				direction = Direction::down;
			break;
		case Direction::down:
			if (_direction == Direction::left)
				direction = Direction::right;
			else
				direction = Direction::left;
			break;
			break;
		case Direction::left:
			if (_direction == Direction::left)
				direction = Direction::down;
			else
				direction = Direction::up;
			break;
		}
	}
};

int main()
{
	cin >> n;
	cin >> appleCount;
	gameMap.resize(n + 1, vector<int>(n + 1));

	for (int i = 0; i < appleCount; ++i)
	{
		pair<int, int> applePosition;
		cin >> applePosition.second >> applePosition.first;
		gameMap[applePosition.second][applePosition.first] = 1;
	}

	cin >> rotationCount;

	for (int i = 0; i < rotationCount; ++i)
	{
		int t;
		char d;
		Direction direction;
		cin >> t >> d;

		if (d == 'L')
			direction = Direction::left;
		else
			direction = Direction::right;
		rotations.insert(make_pair(t, direction));
	}

	Snake* s = new Snake();

	while (true)
	{
		if (!s->Move()) break;

		if (rotations.find(totalTime) == rotations.end())
			continue;

		s->SetDirection(rotations[totalTime]);
	}

	cout << totalTime + 1;
}
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Shortcut
{
public :
	int start, end;

	Shortcut(int _s, int _e) : start(_s), end(_e) {}
};

class Position
{
public :
	int point;
	int depth;
	Shortcut* shortcut = nullptr;

	Position(int _i) : point(_i) {}

	void SetShortcut(Shortcut* s)
	{
		shortcut = s;
	}
};

int Solution(vector<Position*>& map, Position* start)
{
	queue<Position*> q;
	bool visited[100] = {false, };
	q.push(start);
	visited[start->point] = true;

	while (!q.empty())
	{
		Position* currentPosition = q.front();
		q.pop();

		for (int i = 0; i <= 6; ++i)
		{
			if (currentPosition->point + i >= 100)
				return currentPosition->depth + 1;

			if (visited[currentPosition->point + i])
				continue;

			if (map[currentPosition->point + i]->shortcut == nullptr)
			{
				visited[currentPosition->point + i] = true;
				map[currentPosition->point + i]->depth = map[currentPosition->point]->depth + 1;
				q.push(map[currentPosition->point + i]);
			}
			else
			{
				Shortcut* shortcut = map[currentPosition->point + i]->shortcut;
				if (visited[shortcut->end])
					continue;

				visited[shortcut->start] = true;
				visited[shortcut->end] = true;
				map[shortcut->end]->depth = map[currentPosition->point]->depth + 1;
				q.push(map[shortcut->end]);
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

	int n, m;
	cin >> n >> m;

	vector<Position*> map(101);

	int start, end;
	for (int i = 1; i <= 100; ++i)
		map[i] = new Position(i);

	for (int i = 0; i < n + m; ++i)
	{
		cin >> start >> end;

		Shortcut* shortcut = new Shortcut(start, end);
		map[start]->SetShortcut(shortcut);
	}

	cout << Solution(map, map[1]);
}
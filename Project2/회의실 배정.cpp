#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Room
{
public:
	int start, finish;
	Room() { this->start = 0; this->finish = 0; }

	Room(int start, int finish)
	{
		this->start = start;
		this->finish = finish;
	}

	bool operator > (Room& other)
	{
		if (this->finish == other.finish)
			return this->start > other.start;
		return this->finish > other.finish;
	}

	bool operator < (Room& other)
	{
		if (this->finish == other.finish)
			return this->start < other.start;
		return this->finish < other.finish;
	}
};

vector<Room> process(Room* rooms, int n)
{
	sort(rooms, rooms + n);
	vector<Room> v;
	v.push_back(rooms[0]);
	int k = 0;
	for (int i = 1; i < n; i++)
	{
		if (rooms[i].start >= rooms[k].finish)
		{
			k = i;
			v.push_back(rooms[i]);
		}
	}
	return v;
}

int main()
{
	int n;
	cin >> n;
	Room* rooms = new Room[n];
	for (int i = 0; i < n; i++)
	{
		int start, finish;
		cin >> start >> finish;
		rooms[i] = Room(start, finish);
	}
	vector<Room> answer = process(rooms, n);
	cout << answer.size();
}
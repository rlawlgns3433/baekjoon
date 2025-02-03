#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class City
{
public:
	City() {}
	City(int i, bool _visited) : index(i), visited(_visited) { dist = 0; }

	vector<City*> adjacent;
	bool visited;
	int index;
	int dist;
};

void PathFind(vector<City*>& cities, int k, int x)
{
	queue<City*> q;
	cities[x]->visited = true;
	q.push(cities[x]);

	while (!q.empty())
	{
		City* front = q.front();
		q.pop();

		for (auto& adj : front->adjacent)
		{
			if (adj->visited)
				continue;

			adj->visited = true;
			adj->dist = front->dist + 1;
			q.push(adj);
		}
	}

	vector<int> v;

	bool empty = true;
	for (int i = 1; i <= cities.size() - 1; ++i)
	{
		if (cities[i]->dist == k)
		{
			v.push_back(cities[i]->index);
			empty = false;
		}
	}

	sort(v.begin(), v.end());

	for (auto i : v)
		cout << i << '\n';

	if (empty)
		cout << -1;
}

int main()
{
	int n, m, k, x;
	cin >> n >> m >> k >> x;

	vector<City*> cities(n + 1);
	for (int i = 0; i <= n; ++i)
	{
		cities[i] = new City(i, false);
	}

	int start, end;
	for (int i = 0; i < m; ++i)
	{
		cin >> start >> end;
		cities[start]->adjacent.push_back(cities[end]);
	}

	PathFind(cities, k, x);
}
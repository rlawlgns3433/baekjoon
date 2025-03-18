#include <stdio.h>
#include <string.h>
#include <queue>
#include <cmath>
#include <vector>
#define pii pair<int,int>
using namespace std;

vector<vector<pii>> d_map;
int d[20001];

int n, m, start, dest;
int INF = 1000000000;
priority_queue<pii, vector<pii>, greater<pii>> min_heap;

void dijkstra()
{
	d[start] = 0;

	min_heap.push({ 0, start });

	while (!min_heap.empty())
	{
		int dist = min_heap.top().first;
		int src = min_heap.top().second;
		min_heap.pop();

		for (auto& e : d_map[src])
		{
			if (d[e.first] > d[src] + e.second)
			{
				d[e.first] = d[src] + e.second;
				min_heap.push({ e.second + dist, e.first });
			}
		}
	}
}

int main()
{
	scanf("%d %d %d", &n, &m, &start);
	d_map.resize(n + 1);

	for (int i = 0; i <= n; ++i)
	{
		d[i] = INF;
	}

	for (int i = 0; i < m; i++)
	{
		int src, dst, distance;
		scanf("%d %d %d", &src, &dst, &distance);

		d_map[src].push_back({ dst, distance });
	}

	dijkstra();

	for (int i = 1; i <= n; i++)
	{
		if (d[i] == INF) printf("INF\n");
		else printf("%d\n", d[i]);
	}
}
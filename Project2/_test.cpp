#include <iostream>
#include <queue>
#include <cmath>
#include <vector>
#define fastio (ios::sync_with_stdio(0), cin.tie(0))
using namespace std;

typedef pair<int, int> pii;
vector<vector<int>> d_map;
vector<bool> visited;
vector<int> dist;
int v, e, start;
int INF = 1000000000;

void dijkstra(int start)
{
	priority_queue<pii, vector<pii>, greater<pii>> min_heap;
	for (int i = 1; i <= v; i++)
	{
		dist[i] = INF;
	}
	dist[start] = 0;

	min_heap.push(make_pair(dist[start], start));

	while (!min_heap.empty())
	{
		int src = min_heap.top().second;
		min_heap.pop();

		if (visited[src]) continue;
		visited[src] = true;

		for (int dst = 1; dst <= v; dst++)
		{
			if (dist[dst] > dist[src] + d_map[src][dst])
			{
				dist[dst] = dist[src] + d_map[src][dst];
				min_heap.push(make_pair(dist[dst], dst));
			}
		}
	}
}

int main()
{
	fastio;
	cin >> v >> e;
	cin >> start;
	d_map.resize(v + 1, vector<int>(v + 1));
	visited.resize(v + 1);
	dist.resize(v + 1);


	for (int i = 1; i <= v; i++)
	{
		for (int j = 1; j <= v; j++)
		{
			if (i == j) d_map[i][j] = 0;
			else d_map[i][j] = INF;
		}
	}

	for (int i = 1; i <= e; i++)
	{
		int src, dst, weight;
		cin >> src >> dst >> weight;
		if (d_map[src][dst] != INF)
		{
			d_map[src][dst] = min(d_map[src][dst], weight);
		}
		else d_map[src][dst] = weight;
	}
	
	dijkstra(start);
	for (int i = 1; i <= v; i++)
	{
		if (dist[i] == INF) cout << "INF" << endl;
		else cout << dist[i] << endl;
	}
	
}
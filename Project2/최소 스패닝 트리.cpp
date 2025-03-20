#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Edge
{
public:
	int weight, src, dst;

	Edge(int _src, int _dst, int _weight) : src(_src), dst(_dst), weight(_weight) {}

};

struct cmp
{
	bool operator()(Edge* lhs, Edge* rhs)
	{
		return lhs->weight < rhs->weight;
	}
};

int v, e;
vector<int> arr;

int Find(int x)
{
	if (arr[x] == x)
		return x;
	else
		return arr[x] = Find(arr[x]);
}

void Union(int lhs, int rhs)
{
	lhs = Find(lhs);
	rhs = Find(rhs);

	if (lhs != rhs)
		arr[rhs] = lhs;
}

int Solution(vector<Edge*>& edges)
{
	vector<Edge*> tree;
	int answer = 0;
	int i = 0;

	while (tree.size() < v - 1)
	{
		Edge* edge = edges[i];

		int src = edge->src;
		int dst = edge->dst;
		int weight = edge->weight;

		if (Find(src) == Find(dst))
		{
			++i;
			continue;
		}

		tree.push_back(edge);
		Union(src, dst);
		answer += weight;
		++i;
	}

	return answer;
}

int main()
{
	cin >> v >> e;
	arr.resize(v + 1);

	for (int i = 1; i <= v; ++i)
		arr[i] = i;

	vector<Edge*> edges;

	int src, dst, weight;

	for (int i = 0; i < e; ++i)
	{
		cin >> src >> dst >> weight;

		Edge* edge1 = new Edge(src, dst, weight);

		edges.push_back(edge1);
	}

	sort(edges.begin(), edges.end(), cmp());

	cout << Solution(edges);
	return 0;
}
#include <iostream>
#include <stack>
#include <vector>
#include <string.h>
using namespace std;

vector<pair<int, int>> v[10001];
bool visited[10001];
int weightCount = 0;
int answer = 0;

void Solution(int start)
{
	visited[start] = true;
	int sz = v[start].size();

	for (int i = 0; i < sz; ++i)
	{
		if (visited[v[start][i].first])
			continue;

		weightCount += v[start][i].second;
		answer = max(answer, weightCount);
		Solution(v[start][i].first);
		weightCount -= v[start][i].second;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	int parent, child, weight;
	for (int i = 0; i < n - 1; ++i)
	{
		cin >> parent >> child >> weight;

		v[parent].push_back({ child, weight });
		v[child].push_back({ parent, weight });
	}

	for (int i = 1; i <= n; ++i)
	{
		memset(visited, false, n + 1);
		Solution(i);
	}

	cout << answer;
}
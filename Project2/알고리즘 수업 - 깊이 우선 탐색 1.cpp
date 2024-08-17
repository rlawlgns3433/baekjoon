#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

stack<int> stk;
int count = 0;
int n, m, r;
vector<int> visitOrder;
vector<int>* v;

void DFS(int start)
{
	if (visitOrder[start] != 0)
		return;

	stk.push(start);
	while (!stk.empty())
	{
		visitOrder[stk.top()] = ++::count;
		vector<int> temp = v[stk.top()];
		stk.pop();
		for (int i = 0; i < temp.size(); ++i)
		{
			if (visitOrder[temp[i]] != 0)
				continue;

			DFS(temp[i]);
		}
	}
}

int main()
{

	cin >> n >> m >> r;

	visitOrder.resize(n + 1, 0);
	v = new vector<int>[m + 1];

	for (int i = 0; i < m; ++i)
	{
		int src, dst;
		cin >> src >> dst;
		v[src].push_back(dst);
		v[dst].push_back(src);
	}

	for (int i = 1; i <= m; ++i)
	{
		sort(v[i].begin(), v[i].end());
	}

	DFS(r);

	for (int i = 1; i <= n; ++i)
	{
		cout << visitOrder[i] << '\n';
	}
}
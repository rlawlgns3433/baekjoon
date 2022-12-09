#include <iostream>
#include <vector>
#include <limits.h>
#define INF 100000000
using namespace std;

void solution(vector<vector<int>> v, int n)
{
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			if (i == k) continue;
			for (int j = 1; j <= n; j++)
			{
				if (i == j || j == k)continue;
				v[i][j] = min(v[i][j], v[i][k] + v[k][j]);
			}
		}
	}


	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (v[i][j] == INF) cout << 0 << ' ';
			else cout << v[i][j] << ' ';
		}
		cout << endl;
	}
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, bus;
	cin >> n >> bus;

	vector<vector<int>> v;
	v.resize(n + 1, vector<int>(n + 1));

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			v[i][j] = INF;
		}
	}

	for (int i = 1; i <= n; i++)
	{
		v[i][i] = 0;
	}

	for (int i = 0; i < bus; i++)
	{
		int src, dst, weight;
		cin >> src >> dst >> weight;

		if (v[src][dst] != INF)
			v[src][dst] = min(v[src][dst], weight);
		else v[src][dst] = weight;
	}

	solution(v, n);
}
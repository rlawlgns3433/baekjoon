#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> solution(vector<vector<int>> v, int n)
{
	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (v[i][k] + v[k][j] == 2) v[i][j] = 1;
			}
		}
	}
	return v;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	vector<vector<int>> v, sol;
	v.resize(n, vector<int>(n));
	sol.resize(n, vector<int>(n));

	for (int i = 0; i < n; i++)
	{
		v[i][i] = 0;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cin >> v[i][j];
	}

	for (auto& e : solution(v, n))
	{
		for (auto& ee : e)
		{
			cout << ee << ' ';
		}
		cout << endl;
	}
}
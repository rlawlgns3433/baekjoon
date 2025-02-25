#include <iostream>
#include <vector>
#include <algorithm>
#define space ' '
#define endl '\n'
using namespace std;

int n, m;

void solution(const vector<int>& v, vector<int> accum, int count)
{
	if (count == m)
	{
		int accumSize = accum.size();

		for (int i = 0; i < accumSize; ++i)
		{
			cout << accum[i];
			if (i < accumSize - 1)
				cout << space;
		}

		cout << endl;
		return;
	}

	for (int i = 0; i < n; ++i)
	{
		accum.push_back(v[i]);
		solution(v, accum, count + 1);
		accum.pop_back();
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	vector<int> v(n);

	for (int i = 0; i < n; ++i)
	{
		v[i] = i + 1;
	}

	solution(v, {}, 0);
}
#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, l;
	cin >> n >> l;

	vector<int> v(n + 1);

	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
	}

	deque<pair<int, int>> dq;

	for (int i = 1; i <= n; ++i)
	{
		if (!dq.empty())
		{
			if (dq.front().second < i - l + 1)
				dq.pop_front();
		}

		while (!dq.empty() && dq.back().first > v[i])
			dq.pop_back();

		dq.push_back(make_pair(v[i], i));
		cout << dq.front().first << ' ';
	}
	cout << endl;
}
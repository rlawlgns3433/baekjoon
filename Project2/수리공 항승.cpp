#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, l;
	cin >> n >> l;

	vector<int> v(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	int sum = 0;
	int answer = 0;
	int start = 0;
	for (int i = 0; i < n; ++i)
	{
		if (sum == 0)
		{
			start = v[i];
			sum += 1;
			continue;
		}

		if (v[i] - start < l)
		{
			sum = v[i] - start;
		}
		else
		{
			answer++;
			--i;
			sum = 0;
		}
	}
	cout << answer + 1;
}
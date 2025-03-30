#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int m, n;

void Solution(const vector<int>& v)
{
	int left = 1;
	int right = v[n - 1];
	int maxLength = 0;

	while (left <= right)
	{
		int mid = (left + right) / 2;
		int sum = 0;

		for (int i = 0; i < n; ++i)
		{
			sum += (v[i] / mid);
		}

		if (sum >= m)
		{
			left = mid + 1;

			if (maxLength < mid)
				maxLength = mid;
		}
		else
		{
			right = mid - 1;
		}
	}

	cout << maxLength;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> m >> n;

	vector<int> v(n);

	for (int i = 0; i < n; ++i)
		cin >> v[i];

	sort(v.begin(), v.end());

	Solution(v);
}
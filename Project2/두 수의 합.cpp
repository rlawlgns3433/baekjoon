#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> v(n);

	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
	}

	int target;
	cin >> target;

	sort(v.begin(), v.end());

	int left = 0, right = n - 1;
	int answer = 0;
	while (left < right)
	{
		int sum = v[left] + v[right];

		if (sum == target)
		{
			answer++;
			right--;
			continue;
		}

		if (sum < target)
		{
			left++;
		}
		else if (sum > target)
		{
			right--;
		}
	}

	cout << answer;
}
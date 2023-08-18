#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
	int n, k, r;
	cin >> n;

	if (n == 0)
	{
		cout << 0;
		return 0;
	}

	vector<int> arr(n);

	k = round(n * 0.15);

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());

	double sum = 0;

	for (int i = k; i < n - k; i++)
	{
		sum += arr[i];
	}

	int ans = round(sum / (n - k * 2));
	cout << ans;
}
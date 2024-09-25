#include <iostream>
#include <vector>	
using namespace std;

vector<int> arr;
vector<int> dp;

int n;

int main()
{
	cin >> n;

	arr.resize(n + 1);
	dp.resize(n + 1);

	for (int i = 1; i <= n; ++i)
	{
		cin >> arr[i];
	}

	if (n == 1)
	{
		cout << arr[1];
		return 0;
	}
	dp[1] = arr[1];
	if (n >= 2)
	{
		dp[2] = arr[1] + arr[2];
	}


	for (int i = 3; i <= n; ++i) 
	{
		int mx = max(dp[i - 1], dp[i - 2] + arr[i]);
		dp[i] = max(mx, dp[i - 3] + arr[i - 1] + arr[i]);
	}
	cout << dp[n];

	return 0;
}
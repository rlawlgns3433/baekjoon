#include <iostream>
#include <algorithm>
#include <vector>
#define INF 100000000
using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;

	vector<int> coins(n + 1), dp;
	dp.assign(10001, INF);
	dp[0] = 0;

	for (int i = 1; i <= n; i++)
	{
		cin >> coins[i];
	}

	sort(coins.begin(), coins.end());

	for (int i = 1; i <= k; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (coins[j] <= i && (dp[i - coins[j]] + 1 < dp[i]))
				dp[i] = dp[i - coins[j]] + 1;
		}
	}
	if (dp[k] == INF)
	{
		cout << -1;
		return 0;
	}
	cout << dp[k];
}
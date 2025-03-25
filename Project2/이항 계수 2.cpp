#include <iostream>
using namespace std;

int dp[1001][1001];
constexpr int MOD = 10007;

int main()
{
	int n, k;
	cin >> n >> k;

	for (int i = 0; i <= n; ++i)
	{
		dp[i][0] = 1;
		dp[i][i] = 1;

		for (int j = 1; j < i; ++j)
		{
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % MOD;
		}
	}
	cout << dp[n][k] % MOD;
}
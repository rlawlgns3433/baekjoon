#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<vector<int>> arr, dp;
	arr.resize(n, vector<int>(3));
	dp.resize(n, vector<int>(3, 0));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> arr[i][j];

			if (i == 0)
			{
				dp[i][j] = arr[i][j];
				continue;
			}

			if (j == 0)
			{
				dp[i][j] = min(dp[i - 1][j + 1] + arr[i][j], dp[i - 1][j + 2] + arr[i][j]);
			}
			else if (j == 1)
			{
				dp[i][j] = min(arr[i][j] + dp[i - 1][j - 1], arr[i][j] + dp[i - 1][j + 1]);
			}
			else if (j == 2)
			{
				dp[i][j] = min(dp[i - 1][j - 1] + arr[i][j], dp[i - 1][j - 2] + arr[i][j]);
			}
		}
	}

	int ans = min(dp[n - 1][0], min(dp[n - 1][1], dp[n - 1][2]));

	cout << ans;
}
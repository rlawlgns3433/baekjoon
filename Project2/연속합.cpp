#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> dp(n, 0);
	vector<int> v(n, 0);
	int number;
	int answer;

	for (int i = 0; i < n; ++i)
		cin >> v[i];

	dp[0] = v[0];
	answer = dp[0];

	for (int i = 1; i < n; ++i)
	{
		dp[i] = max(dp[i - 1] + v[i], v[i]);
		answer = max(dp[i], answer);
	}

	cout << answer;
}
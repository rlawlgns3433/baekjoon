#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<int> v(n + 1, 0);
	vector<int> dp(n + 1);
	cin >> v[1];
	dp[1] = v[1];
	for (int i = 2; i <= n; ++i)
	{
		cin >> v[i];
		dp[i] += dp[i - 1] + v[i];
	}

	int testcase;
	cin >> testcase;

	int start, end;

	for (int i = 0; i < testcase; ++i)
	{
		cin >> start >> end;

		cout << dp[end] - dp[start - 1] << '\n';
	}
}
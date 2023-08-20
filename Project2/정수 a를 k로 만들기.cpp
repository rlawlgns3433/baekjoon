#include <iostream>
using namespace std;

int dp[1000000];

int main()
{
	int a, k;
	cin >> a >> k;

	dp[a] = 0;

	for (int i = a + 1; i <= k; i++)
	{
		dp[i] = dp[i - 1] + 1; // 홀수일 때
		// a의 두 배 이상 짝수일 때
		if (i % 2 == 0 && i / 2 >= a) dp[i] = min(dp[i], dp[i / 2] + 1);
	}
	cout << dp[k];
}
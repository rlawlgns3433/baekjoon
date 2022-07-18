#include <iostream>
using namespace std;
int n0 = 0, n1 = 1, n2 = 2, n3 = 4;
int dp[10] = { n0, n1, n2, n3, };
int main()
{


	for (int i = 4; i < 11; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		cout << dp[num] << '\n';
	}
}
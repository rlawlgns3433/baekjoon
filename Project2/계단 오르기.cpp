#include <iostream>
#include <vector>
using namespace std;

vector<int> dp;
vector<int> step_score;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	
	int n;
	cin >> n;

	dp.resize(n+1);
	step_score.resize(n+1);

	for (int i = 1; i <= n; i++)
	{
		cin >> step_score[i];
	}

	dp[1] = step_score[1];
	dp[2] = step_score[1] + step_score[2];

	for (int i = 3; i <= n; i++)
	{
		dp[i] = max(dp[i - 2] + step_score[i], dp[i - 3] + step_score[i-1] + step_score[i]);
	}

	cout << dp[n];
}
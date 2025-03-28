#include <iostream>
#include <vector>
using namespace std;

int c, n;
constexpr int inf = 210000000;
void Input(vector<pair<int, int>>&);
void Solution(vector<pair<int, int>>&);

void Input(vector<pair<int, int>>& object)
{
	for (int i = 1; i <= n; ++i)
	{
		cin >> object[i].first >> object[i].second;
	}
}

void Solution(vector<pair<int, int>>& object)
{
	vector<int> dp(c + 101, inf);
	dp[0] = 0;
	int answer = inf;

	for (int i = 1; i <= n; ++i)
	{
		int cost = object[i].first;
		int customer = object[i].second;

		for (int j = customer; j <= c + 100; ++j)
		{
			dp[j] = min(dp[j], dp[j - customer] + cost);
		}
	}
	for (int i = c; i <= c + 100; ++i)
	{
		answer = min(answer, dp[i]);
	}

	cout << answer;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> c >> n;

	vector<pair<int, int>> object(n + 1);

	Input(object);
	Solution(object);
}
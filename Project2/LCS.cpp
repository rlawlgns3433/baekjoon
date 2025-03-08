#include <iostream>
#include <vector>
using namespace std;

int main()
{
	string str1, str2;
	cin >> str1 >> str2;

	int str1Size = str1.size();
	int str2Size = str2.size();

	vector<vector<int>> dp(str2Size + 1, vector<int>(str1Size + 1));
	for (int i = 0; i <= str2Size; ++i)
	{
		for (int j = 0; j <= str1Size; ++j)
		{
			if (i == 0 || j == 0)
				dp[i][j] = 0;
			else if (str1[j - 1] == str2[i - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
		}
	}

	cout << dp[str2Size][str1Size];
}
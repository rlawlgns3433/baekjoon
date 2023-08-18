#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str1, str2;
	cin >> str1 >> str2;

	int sz1 = str1.size(), sz2 = str2.size();
	int mx = 0;
	int **dp = new int*[sz1];
	
	for (int i = 0; i < sz1; i++)
	{
		dp[i] = new int[sz2];
	}

	for (int i = 0; i < sz1; i++)
	{
		for (int j = 0; j < sz2; j++)
		{
			dp[i][j] = 0;
		}
	}

	for (int i = 0; i < sz1; i++)
	{
		for (int j = 0; j < sz2; j++)
		{
			if (str1[i] == str2[j])
			{
				dp[i][j] = 1;
				if (i > 0 && j > 0)
				{
					dp[i][j] = dp[i][j] + dp[i - 1][j - 1];
				}
				mx = max(mx, dp[i][j]);
			}
		}
	}

	//for (int i = 0; i < sz1; i++)
	//{
	//	for (int j = 0; j < sz2; j++)
	//	{
	//		cout << dp[i][j] << ' ';
	//	}
	//	cout << '\n';
	//}


	cout << mx;
}
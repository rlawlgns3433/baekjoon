#include <iostream>
#include <vector>
#include <stdint.h>
using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> data;
	vector<int> arr(n + 1);
	vector<vector<int>> c(n + 1, vector<int>(n + 1));

	int d0, d1;
	cin >> d0 >> d1;

	if (n == 1)
	{
		cout << d0 * d1;
		return 0;
	}

	data.push_back(d0);
	data.push_back(d1);

	for (int i = 0; i < n - 1; ++i)
	{
		int d, dd;
		cin >> d >> dd;
		data.push_back(dd);
	}

	for (int i = 1; i <= n; ++i)
	{
		c[i][i] = 0;
		arr[i] = data[i - 1] * data[i];
	}

	for (int i = 1; i <= n - 1; ++i)
	{
		for (int j = 1; j <= n - i; ++j)
		{
			int t = i + j;
			c[j][t] = INT32_MAX;

			for (int k = j; k < t; ++k)
			{
				int temp = c[j][k] + c[k + 1][t] + data[j - 1] * data[k] * data[t];
				if (temp < c[j][t])
					c[j][t] = temp;
			}
		}
	}

	cout << c[1][n];
}
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> arr;
	arr.resize(m);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	int result = 0;
	int sum = 0;

	for (int i = 0; i < n - 2; i++)
	{
		for (int j = i + 1; j < n - 1; j++)
		{
			for (int k = j + 1; k < n; k++)
			{
				sum = arr[i] + arr[j] + arr[k];
				if (sum > result && sum <= m)
					result = sum;
			}
		}
	}
	cout << result;
}
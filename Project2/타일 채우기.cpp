#include <iostream>
#include <vector>
using namespace std;

int v[30] = { 0, 3, 0, 11, 0, 41, 0 };
int sol(int n)
{
	for (int i = 7; i < n; i++)
	{
		if (i % 2 == 0)
		{
			continue;
		}

		v[i] = (v[i - 4] + v[i - 2]) * 3 - v[i - 6];
	}

	return v[n - 1];
}

int main()
{
	int n;
	cin >> n;

	cout << sol(n);
}
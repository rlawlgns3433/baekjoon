#include <iostream>
using namespace std;

int n, k;

int main()
{
	cin.tie(0); cin.sync_with_stdio(0);
	long long answer;
	while (1)
	{
		cin >> n >> k;
		if (n == 0 && k == 0) break;

		k = min(k, n - k);

		long long answer = 1;

		for (int i = 1; i <= k; i++)
		{
			answer *= n;
			answer /= i;
			n--;
		}
		cout << answer << '\n';
	}
}
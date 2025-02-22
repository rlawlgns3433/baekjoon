#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<long long> v(n + 1);

	v[1] = 1;
	for (int i = 2; i <= n; ++i)
	{
		if (i % 2 == 0)
			v[i] = (v[i - 1] * 2 + 1) % 10007;
		else
			v[i] = (v[i - 1] * 2 - 1) % 10007;
	}

	cout << v[n];
}
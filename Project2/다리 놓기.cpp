#include <iostream>
#define endl '\n'
using namespace std;

void Testcase(int n, int m)
{
	int result = 1;
	int r = 1;
	for (int i = m; i > n; --i)
	{
		result *= i;
		result /= r;
		r++;
	}

	cout << result << endl;
}

int main()
{
	int tc;
	cin >> tc;

	int n, m;

	for (int i = 0; i < tc; ++i)
	{
		cin >> n >> m;
		Testcase(n, m);
	}
}
#include <iostream>
#include <vector>
#define fastio (cin.tie(0), cout.tie(0), ios::sync_with_stdio(0))
using namespace std;

vector<long long> v;

int main()
{
	fastio;

	v.resize(101);
	v[0] = 0;
	v[1] = v[2] = v[3] = 1;

	for (int i = 4; i <= 100; i++)
	{
		v[i] = v[i - 2] + v[i - 3];
	}

	int T;

	cin >> T;

	for (int i = 0; i < T; i++)
	{
		int k;
		cin >> k;
		cout << v[k] << '\n';
	}

	return 0;
}
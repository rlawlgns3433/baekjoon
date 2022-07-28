#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> a, b;
	a.resize(n); b.resize(n);

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	for (int i = 0; i < n; i++)
	{
		cin >> b[i];
	}

	sort(a.begin(), a.end());
	sort(b.rbegin(), b.rend());

	int sum = 0;

	for (int i = 0; i < n; i++)
	{
		sum += a[i] * b[i];
	}
	cout << sum;
}
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


void testcase(int index)
{


	int n;
	cin >> n;

	vector<int> v(n);

	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	int gap = 0;
	for (int i = 0; i < n - 1; i++)
	{
		if (v[i + 1] - v[i] > gap)
		{
			gap = v[i + 1] - v[i];
		}
	}


	cout << "Class " << index + 1 << '\n';
	cout << "Max " << v[n - 1] << ", Min " << v[0] << ", Largest gap " << gap << '\n';
}

int main()
{
	int tc;


	cin >> tc;

	int num_st;


	for (int i = 0; i < tc; i++)
	{
		testcase(i);
	}
}
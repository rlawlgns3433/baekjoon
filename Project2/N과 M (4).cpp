#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;

void Solution(const vector<int>& v, vector<int> currentV, int n, int k, int cnt, int curVal)
{
	if (cnt == k)
	{
		for (auto e : currentV)
			cout << e << ' ';

		cout << endl;
		return;
	}

	for (int i = curVal; i < n; ++i)
	{
		currentV.push_back(i + 1);
		Solution(v, currentV, n, k, cnt + 1, i);
		currentV.pop_back();
	}
}

int main()
{
	int n, k;
	cin >> n >> k;

	vector<int> v;
	for (int i = 0; i < n; ++i)
	{
		v.push_back(i + 1);
	}

	Solution(v, vector<int>(), n, k, 0, 0);
}
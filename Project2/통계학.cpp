#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <unordered_map>
using namespace std;

bool Compare(pair<int, int> lhs, pair<int, int> rhs)
{
	if (lhs.second == rhs.second)
		return lhs.first < rhs.first;

	return lhs.second > rhs.second;
}

int main()
{
	int n;
	cin >> n;
	vector<int> v(n);
	unordered_map<int, int> mp;
	int sum = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
		sum += v[i];
		mp[v[i]]++;
	}

	int avg = round(sum / (float)n);

	sort(v.begin(), v.end());

	int mid = v[n / 2];

	vector<pair<int, int>> mpV(mp.begin(), mp.end());
	sort(mpV.begin(), mpV.end(), Compare);

	int mfv = mpV[0].first;
	if (mpV.size() > 1 && mpV[0].second == mpV[1].second)
	{
		mfv = mpV[1].first;
	}

	int range = v[n - 1] - v[0];

	cout << avg << '\n' << mid << '\n' << mfv << '\n' << range;
}
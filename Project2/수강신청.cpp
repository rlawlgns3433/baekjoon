#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iomanip>
using namespace std;

int main()
{
	int k, l;
	cin >> k >> l;

	unordered_map<int, int> studentClick;
	int snumber;
	int rank = 0;

	for (int i = 0; i < l; ++i)
	{
		cin >> snumber;
		studentClick[snumber] = ++rank;
	}

	vector<pair<int, int>> v(studentClick.begin(), studentClick.end());

	sort(v.begin(), v.end(), [](pair<int, int> lhs, pair<int, int> rhs)
		{
			return lhs.second < rhs.second;
		});

	rank = 0;
	for (const auto& it : v)
	{
		if (rank == k) break;
		cout << setw(8) << setfill('0') << it.first << '\n';
		rank++;
	}
}

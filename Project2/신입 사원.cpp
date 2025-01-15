#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool Compare(pair<int, int> lhs, pair<int, int> rhs)
{
	if (lhs.first < rhs.first)
		return true;
	return false;
}

int main()
{
	int tc = 0;
	cin >> tc;
	int sc = 0;

	for (int i = 0; i < tc; ++i)
	{
		int firstScore = 0;
		int secondScore = 0;
		cin >> sc;
		vector<pair<int, int>> scores(sc);
		int answer = 1;
		for (int j = 0; j < sc; ++j)
		{
			cin >> firstScore >> secondScore;
			scores[j].first = firstScore;
			scores[j].second = secondScore;
		}

		sort(scores.begin(), scores.end(), Compare);


		int minSecond = scores[0].second;

		for (int j = 1; j < sc; ++j)
		{
			if (minSecond > scores[j].second)
			{
				minSecond = scores[j].second;
				answer++;
			}
		}
		cout << answer << '\n';
	}
}
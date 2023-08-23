#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define pii pair<int,int>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<pii> lectures;
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	for (int i = 0; i < n; i++)
	{
		int idx, s, e;
		cin >> idx >> s >> e;
		pq.push({ s, e });
	}

	vector<int> end_times;

	while (!pq.empty())
	{
		int start = pq.top().first;
		int end = pq.top().second;

		pq.pop();

		for (int i = 0; i < end_times.size(); i++)
		{
			if (end_times[i] <= start)
			{
				end_times.erase(end_times.begin() + i);
				break;
			}
		}
		end_times.push_back(end);
	}
	cout << end_times.size() << endl;
}
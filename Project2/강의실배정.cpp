#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define pii pair<int,int>
#define fastio (ios::sync_with_stdio(0), cin.tie(0))
using namespace std;

priority_queue<int, vector<int>, greater<int>> min_heap;
vector<pii> lectures;

int solution()
{
	min_heap.push(lectures[0].second);
	int l_size = lectures.size() - 1;
	int i = 1;

	while (l_size--)
	{
		min_heap.push(lectures[i].second);
		if (min_heap.top() <= lectures[i].first)
		{
			min_heap.pop();
		}
		i++;
	}
	return min_heap.size();
}

int main()
{
	fastio;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int start_t, end_t;
		cin >> start_t >> end_t;
		lectures.push_back(make_pair(start_t, end_t));
	}
	sort(lectures.begin(), lectures.end());

	cout << solution();
}

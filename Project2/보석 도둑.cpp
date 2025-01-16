#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	vector<pair<int, int>> jewels;
	vector<int> bags;
	priority_queue<int, vector<int>, less<int>> pq;

	for (int i = 0; i < n; ++i)
	{
		int weight, value;
		cin >> weight >> value;

		jewels.push_back(make_pair(weight, value));
	}

	for (int i = 0; i < k; ++i)
	{
		int capacity;
		cin >> capacity;

		bags.push_back(capacity);
	}

	sort(jewels.begin(), jewels.end());
	sort(bags.begin(), bags.end());

	int current_index = 0;
	long long answer = 0;

	for (int i = 0; i < k; ++i)
	{
		while (current_index < n && bags[i] >= jewels[current_index].first)
		{
			pq.push(jewels[current_index].second);
			current_index++;
		}
		if (!pq.empty())
		{
			answer += pq.top();
			pq.pop();
		}
	}

	cout << answer;
}

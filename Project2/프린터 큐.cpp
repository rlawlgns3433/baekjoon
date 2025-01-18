#include <iostream>
#include <queue>
using namespace std;

int TestCase()
{
	queue<pair<int, int>> q; // (초기 위치, 우선 순위)
	priority_queue<int, vector<int>> pq;
	int answer = 0;
	int n, searchPosition;
	cin >> n >> searchPosition;

	for (int i = 1; i <= n; ++i)
	{
		int prior;
		cin >> prior;

		q.push(make_pair(i, prior));
		pq.push(prior);
	}

	while (true)
	{
		pair<int, int> front;
		while (pq.top() != q.front().second)
		{
			front = q.front();
			q.push(front);
			q.pop();
		}
		front = q.front();

		pq.pop();
		q.pop();
		answer++;

		if (front.first == searchPosition + 1)
			return answer;
	}

	return answer;
}

int main()
{
	int tc;
	cin >> tc;

	for (int i = 0; i < tc; ++i)
	{
		cout << TestCase() << '\n';
	}
}
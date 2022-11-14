// 1697 숨바꼭질
#include <iostream>
#include <queue>
using namespace std;

// 가능한 연산
// 1. x + 1, x - 1
// 2. 2 * x

queue<int> q;
int dp[100001];

bool pos[100001], visited[100001];
static int cnt = 0;

void bfs(int n, int k)
{
	q.push(n);
	visited[n] = true;
	while (!q.empty())
	{
		int x = q.front();
		q.pop();

		if (x == k) break;

		if (!visited[x + 1] && x + 1 < 100001)
		{
			q.push(x + 1);
			visited[x + 1] = true;
			dp[x + 1] = dp[x] + 1;
		}

		if (!visited[x - 1] && x - 1 >= 0)
		{
			q.push(x - 1);
			visited[x - 1] = true;
			dp[x - 1] = dp[x] + 1;
		}

		if (!visited[x * 2] && x * 2 >= 0 && x * 2 < 100001)
		{
			q.push(x * 2);
			visited[x * 2] = true;
			dp[x * 2] = dp[x] + 1;
		}
	}
}

int main()
{
	int n, k;
	cin >> n >> k;

	bfs(n, k);

	cout << dp[k];
}
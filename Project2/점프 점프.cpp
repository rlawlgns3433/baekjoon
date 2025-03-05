#include <iostream>
#include <set>
#include <vector>
using namespace std;

int n;
int start;

set<int> answer;

void Solution(int start, const vector<int>& v)
{
	if (answer.find(start) != answer.end())
		return;

	answer.insert(start);
	if (start + v[start] <= n) Solution(start + v[start], v);
	if (start - v[start] > 0) Solution(start - v[start], v);
}

int main()
{
	cin >> n;
	vector<int> v(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
	}

	cin >> start;
	Solution(start, v);

	cout << answer.size();
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<vector<int>> answer;

void Solution(const vector<int>& v, vector<int> currentArray, int current, int count)
{
	if (count == m)
	{
		answer.push_back(currentArray);
		return;
	}

	for (int i = 0; i < n; ++i)
	{
		if (current == v[i])
			continue;

		if (find(currentArray.begin(), currentArray.end(), v[i]) != currentArray.end())
			continue;

		currentArray.push_back(v[i]);
		Solution(v, currentArray, v[i], count + 1);
		currentArray.pop_back();
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	vector<int> v(n);

	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
	}

	for (int i = 0; i < n; ++i)
	{
		Solution(v, { v[i] }, v[i], 1);
	}

	sort(answer.begin(), answer.end());

	for (auto& v : answer)
	{
		for (auto& e : v)
		{
			cout << e << ' ';
		}
		cout << '\n';
	}
}
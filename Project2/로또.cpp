#include <iostream>
#include <vector>
using namespace std;

constexpr char endl = '\n';

void Solution(const vector<int>& v, int ballCount, vector<int> current, vector<bool> visited, int currentBallCount = 0)
{
	if (currentBallCount == 6)
	{
		for (int i = 0; i < 6; ++i)
		{
			cout << current[i] << " ";
		}
		cout << ::endl;
	}

	for (int i = currentBallCount; i < ballCount; ++i)
	{
		if (visited[i])
			continue;

		current.push_back(v[i]);
		visited[i] = true;
		Solution(v, ballCount, current, visited, currentBallCount + 1);
		current.pop_back();
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int ballCount;

	while (true)
	{
		cin >> ballCount;
		if (ballCount == 0)
			break;
		vector<int> v(ballCount);
		for (int i = 0; i < ballCount; ++i)
		{
			cin >> v[i];
		}

		Solution(v, ballCount, {}, vector<bool>(ballCount));
		cout << ::endl;
	}
}
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> v;
vector<pair<int, int>> chickenHouse;
vector<pair<int, int>> houses;
vector<int> visited;
int n, m;
int chickenHouseCount, housesCount;
unsigned long long answer = 2100000000;

unsigned long long Distance(pair<int, int> lhs, pair<int, int> rhs)
{
	return abs(lhs.first - rhs.first) + abs(lhs.second - rhs.second);
}

void Solution(int idx, int cnt)
{
	if (cnt == m)
	{
		unsigned long long tmpAns = 0;
		for (int i = 0; i < housesCount; ++i)
		{
			unsigned long long tmp = 2100000000;

			for (int j = 0; j < cnt; ++j)
			{
				tmp = min(tmp, Distance(chickenHouse[visited[j]], houses[i]));
			}
			tmpAns += tmp;
		}
		answer = min(tmpAns, answer);

		return;
	}

	for (int i = idx; i < chickenHouseCount; ++i)
	{
		visited.push_back(i);
		Solution(i + 1, cnt + 1);
		visited.pop_back();
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	v.resize(n, vector<int>(n));

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> v[i][j];
			if (v[i][j] == 2)
				chickenHouse.push_back({ i, j });
			else if (v[i][j] == 1)
				houses.push_back({ i, j });
		}
	}
	chickenHouseCount = chickenHouse.size();
	housesCount = houses.size();
	Solution(0, 0);
	cout << answer;
}
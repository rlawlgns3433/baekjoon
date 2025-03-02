#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n;
int minHeight = 100, maxHeight = 1;
int height;

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

class District
{
public:
	District(int _y, int _x, int _height) : y(_y), x(_x), height(_height)
	{
		flood = false;
		visited = false;
	}

	bool GetFlood()
	{
		return flood;
	}
	void SetFlood(bool _flood)
	{
		flood = _flood;
	}
	void ResetFlood()
	{
		flood = false;
	}

	bool GetVisited()
	{
		return visited;
	}

	void SetVisited(bool _visited)
	{
		visited = _visited;
	}

	int GetHeight()
	{
		return height;
	}

	int GetX()
	{
		return x;
	}

	int GetY()
	{
		return y;
	}

private:
	int y, x, height;
	bool flood;
	bool visited;
};

int Solution(const vector<vector<District*>>& v, int startY, int startX, int height)
{
	if (v[startY][startX]->GetVisited() || v[startY][startX]->GetFlood())
		return 0;

	queue<District*> q;
	q.push(v[startY][startX]);

	while (!q.empty())
	{
		District* currentDistrict = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int x = dx[i] + currentDistrict->GetX();
			int y = dy[i] + currentDistrict->GetY();

			if (x < 0 || y < 0 || x >= n || y >= n)
				continue;

			if (v[y][x]->GetVisited() || v[y][x]->GetFlood())
				continue;

			q.push(v[y][x]);
			v[y][x]->SetVisited(true);
		}
	}

	return 1;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	vector<vector<District*>> v(n, vector<District*>(n));

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> height;
			District* district = new District(i, j, height);

			if (height > maxHeight)
				maxHeight = height;

			if (height < minHeight)
				minHeight = height;

			v[i][j] = district;
		}
	}

	if (minHeight == maxHeight)
	{
		cout << 1;
		return 0;
	}

	int answer = 0;
	int temp = 0;
	for (int height = minHeight; height <= maxHeight; ++height)
	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (v[i][j]->GetHeight() <= height)
					v[i][j]->SetFlood(true);
			}
		}

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				temp += Solution(v, i, j, height);
			}
		}

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				v[i][j]->SetVisited(false);
			}
		}

		answer = max(answer, temp);
		temp = 0;
	}

	cout << answer;
	return 0;
}
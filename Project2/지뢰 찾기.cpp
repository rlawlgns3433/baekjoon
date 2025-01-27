#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;

int n;
int dx[] = { -1,-1,-1,0,0,1,1,1 };
int dy[] = { -1,0,1,-1,1,-1,0,1 };
bool gameover = false;
vector<vector<char>> originMap, openedMap;
vector<pair<int, int>> bombs;

void SettingMap()
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> originMap[i][j];
			if (originMap[i][j] == '*')
				bombs.push_back(make_pair(i, j));
		}
	}
}

char CheckMap(int i, int j)
{
	if (originMap[i][j] == '*')
		gameover = true;

	int count = 0;
	for (int a = 0; a < 8; ++a)
	{
		int x = j + dx[a];
		int y = i + dy[a];

		if (x < 0 || x >= n || y < 0 || y >= n)
			continue;

		if (originMap[y][x] == '*')
			count++;
	}

	return 0x30 + count;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	originMap.resize(n, vector<char>(n));
	openedMap.resize(n, vector<char>(n));

	SettingMap();

	char c;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> c;
			if (c == '.')
				openedMap[i][j] = c;
			else
				openedMap[i][j] = CheckMap(i, j);
		}
	}

	if (gameover)
	{
		for (int i = 0; i < bombs.size(); ++i)
		{
			auto bomb = bombs[i];
			openedMap[bomb.first][bomb.second] = '*';
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout << openedMap[i][j];
		}
		cout << endl;
	}
}
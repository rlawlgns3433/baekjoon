#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#define endl '\n'
using namespace std;

vector<string> answer;
vector<char> v;

int vox = 0b00001111;
int con = 0b11110000;

void solution(int l, int c, pair<string, int> currentString, int cnt, int index, bool visited[])
{
	if (l == cnt)
	{
		int vox_cnt = currentString.second & vox;
		int con_cnt = (currentString.second & con) >> 4;

		if (vox_cnt < 1 || con_cnt < 2)
			return;

		answer.push_back(currentString.first);
		return;
	}

	for (int i = index; i < c; ++i)
	{
		if (!visited[i])
		{
			visited[i] = true;

			if (v[i] == 'a' || v[i] == 'e' || v[i] == 'i' || v[i] == 'o' || v[i] == 'u')
				solution(l, c, make_pair(currentString.first + v[i], currentString.second + 1), cnt + 1, i + 1, visited);
			else
				solution(l, c, make_pair(currentString.first + v[i], currentString.second + (1 << 4)), cnt + 1, i + 1, visited);

			visited[i] = false;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int l, c;
	bool visited[20] = { false, };
	cin >> l >> c;

	v.resize(c);
	for (int i = 0; i < c; ++i)
		cin >> v[i];

	sort(v.begin(), v.end());
	solution(l, c, make_pair("", 0), 0, 0, visited);

	for (auto s : answer)
		cout << s << endl;
}
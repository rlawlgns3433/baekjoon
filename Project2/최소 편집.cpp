#include <iostream>
#include <string>
#include <algorithm>
#define fastio (ios::sync_with_stdio(0), cin.tie(0))
using namespace std;

void EditDistance(string s1, string s2);

int v[1001][1001];

int main()
{
	string s1, s2;
	cin >> s1 >> s2;

	EditDistance(s1, s2);
}

void EditDistance(string s1, string s2)
{
	int m_s1_len = s1.length(), m_s2_len = s2.length();

	for (int i = 1; i <= m_s1_len; i++) v[i][0] = i;
	for (int j = 1; j <= m_s2_len; j++) v[0][j] = j;

	for (int i = 1; i <= m_s1_len; i++)
	{
		for (int j = 1; j <= m_s2_len; j++)
		{
			if (s1[i - 1] == s2[j - 1])
				v[i][j] = v[i - 1][j - 1];
			else
				v[i][j] = min(v[i][j - 1] + 1, min(v[i - 1][j] + 1, v[i - 1][j - 1] + 1));
		}
	}
	cout << v[m_s1_len][m_s2_len];
}
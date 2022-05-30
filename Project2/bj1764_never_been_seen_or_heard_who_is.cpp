#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

int n, m;
set<string> s1;
vector<string> v, ans;
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		s1.insert(str);
	}

	for (int i = 0; i < m; i++)
	{
		string str;
		cin >> str;
		v.push_back(str);
	}
	for (int i = 0; i < m; i++) 
	{
		if (s1.find(v[i]) != s1.end())
		{
			ans.push_back(v[i]);
		}
	}
	cout << ans.size() << '\n';
	sort(ans.begin(), ans.end());
	for (auto& e : ans)
	{
		cout << e << '\n';
	}
}
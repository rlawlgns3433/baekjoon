#include <iostream>
#include <string>
#include <set>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string str;
	cin >> str;

	set<string> s;
	int strSize = str.size();
	for (int i = 0; i < strSize; ++i)
	{
		for (int j = 1; j <= strSize; ++j)
		{
			s.insert(str.substr(i, j));
		}
	}
	cout << s.size();
}
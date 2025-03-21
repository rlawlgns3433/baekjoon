#include <iostream>
#include <list>
#include <string>
using namespace std;

string Solution(string& str)
{
	list<char> result;
	auto cursor = result.begin();

	for (char ch : str)
	{
		if (ch == '<') {
			if (cursor != result.begin())
				--cursor;
		}
		else if (ch == '>') {
			if (cursor != result.end())
				++cursor;
		}
		else if (ch == '-') {
			if (cursor != result.begin()) {
				auto erase_pos = cursor;
				--erase_pos;
				cursor = result.erase(erase_pos);
			}
		}
		else {
			cursor = result.insert(cursor, ch);
			++cursor;
		}
	}

	return string(result.begin(), result.end());
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	string str;

	for (int i = 0; i < n; ++i)
	{
		cin >> str;
		cout << Solution(str) << '\n';
	}
}

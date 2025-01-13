#include <iostream>
#include <string>
#include <list>
using namespace std;

int main()
{
	string str;
	int c;

	cin >> str;
	cin >> c;
	list<char> l(str.begin(), str.end());
	list<char>::iterator it = l.end();

	for (int i = 0; i < c; ++i)
	{
		char cmd;
		cin >> cmd;
		if (cmd == 'P')
		{
			char ch;
			cin >> ch;

			l.insert(it, ch);
		}
		else if (cmd == 'L')
		{
			if (it == l.begin())
				continue;

			it--;
		}
		else if (cmd == 'D')
		{
			if (it == l.end())
				continue;
			it++;
		}
		else if (cmd == 'B')
		{
			if (it == l.begin())
				continue;
			it--;
			it = l.erase(it);
		}
	}
	for (it = l.begin(); it != l.end(); ++it)
	{
		cout << *it;
	}
}
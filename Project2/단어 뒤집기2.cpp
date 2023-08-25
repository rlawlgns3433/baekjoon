#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

int main()
{
	string str;
	getline(cin, str);

	stack<char> stk;

	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '<')
		{
			while (!stk.empty())
			{
				cout << stk.top();
				stk.pop();
			}
			cout << str[i];
			while (str[i] != '>')
			{
				cout << str[++i];
			}
		}
		else if (str[i] == ' ')
		{
			while (!stk.empty())
			{
				cout << stk.top();
				stk.pop();
			}
			cout << ' ';
		}
		else stk.push(str[i]);
	}

	while (!stk.empty())
	{
		cout << stk.top();
		stk.pop();
	}
}
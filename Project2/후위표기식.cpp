#include <iostream>
#include <string>
#include <stack>
using namespace std;

stack<char> stk;

void process(string exp)
{
	for (int i = 0; i < exp.length(); i++)
	{

		if (exp[i] == '+' || exp[i] == '-')
		{
			while (!stk.empty() && stk.top() != '(')
			{
				cout << stk.top();
				stk.pop();
			}
			stk.push(exp[i]);
		}
		else if (exp[i] == '*' || exp[i] == '/')
		{
			while (!stk.empty() && (stk.top() == '*' || stk.top() == '/'))
			{
				cout << stk.top();
				stk.pop();
			}
			stk.push(exp[i]);
		}
		else if (exp[i] == '(')
		{
			stk.push(exp[i]);
		}
		else if (exp[i] == ')')
		{
			while (!stk.empty() && stk.top() != '(')
			{
				cout << stk.top();
				stk.pop();
			}
			stk.pop();
		}
		else
		{
			cout << exp[i];
		}
	}
	while (!stk.empty())
	{
		cout << stk.top();
		stk.pop();
	}
}

int main()
{
	string expression;

	cin >> expression;

	process(expression);
}
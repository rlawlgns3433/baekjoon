#include <iostream>
#include <stack>
using namespace std;

int main()
{
	int count = 0;
	stack<char> stk;
	string pipe;
	cin >> pipe;

	for (int i = 0; i < pipe.size(); ++i)
	{
		if (pipe[i] == '(')
		{
			stk.push('(');
		}
		else if (pipe[i] == ')' && pipe[i - 1] == '(')
		{
			stk.pop();
			count += stk.size();
		}
		else
		{
			stk.pop();
			count += 1;
		}
	}

	cout << count;
}
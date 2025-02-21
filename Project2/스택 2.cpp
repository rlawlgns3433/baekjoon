#include <iostream>
#include <stack>
#define endl '\n'
using namespace std;

stack<int> stk;

void Command(int cmd)
{
	switch (cmd)
	{
	case 1:
		int val;
		cin >> val;
		stk.push(val);
		break;
	case 2:
		if (!stk.empty())
		{
			cout << stk.top() << endl;
			stk.pop();
		}
		else
		{
			cout << -1 << endl;
		}
		break;
	case 3:
		cout << stk.size() << endl;
		break;
	case 4:
		if (stk.empty())
			cout << 1 << endl;
		else
			cout << 0 << endl;
		break;
	case 5:
		if (!stk.empty())
			cout << stk.top() << endl;
		else
			cout << -1 << endl;
		break;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	int cmd;
	for (int i = 0; i < n; ++i)
	{
		cin >> cmd;
		Command(cmd);
	}
}
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
	int n;
	cin >> n;

	stack<int> stk;
	vector<char> result;
	int cur = 1;

	for (int i = 0; i < n; ++i)
	{
		int num;
		cin >> num;

		while (cur <= num)
		{
			stk.push(cur);
			cur++;
			result.push_back('+');
		}

		if (stk.top() == num)
		{
			stk.pop();
			result.push_back('-');
		}
		else
		{
			cout << "NO";
			return 0;
		}
	}

	for (int i = 0; i < result.size(); ++i)
	{
		cout << result[i] << '\n';
	}
}
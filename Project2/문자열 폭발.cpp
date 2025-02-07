#include <iostream>
#include <stack>	
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string str, bomb;
	cin >> str >> bomb;

	stack<char> stk;

	string answer;
	int strSize = str.size();
	int bombSize = bomb.size();
	for (int i = 0; i < strSize; ++i)
	{
		stk.push(str[i]);

		if (str[strSize - 1] && stk.size() >= bombSize)
		{
			string temp;

			for (int j = 0; j < bombSize; ++j)
			{
				temp += stk.top();
				stk.pop();
			}

			reverse(temp.begin(), temp.end());

			if (bomb.compare(temp) != 0)
			{
				for (int j = 0; j < bombSize; ++j)
				{
					stk.push(temp[j]);
				}
			}
		}
	}

	while (!stk.empty())
	{
		answer += stk.top();
		stk.pop();
	}

	reverse(answer.begin(), answer.end());

	if (answer.size() > 0)
		cout << answer;
	else
		cout << "FRULA";
}
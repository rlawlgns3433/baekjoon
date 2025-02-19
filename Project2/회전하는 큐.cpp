#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int n, m;

void Input(vector<int>& commands, deque<int>& dq)
{
	for (int i = 0; i < n; ++i)
	{
		dq.push_back(i + 1);
	}

	for (int i = 0; i < m; ++i)
	{
		int command;
		cin >> command;
		commands.push_back(command);
	}
}

int IndexOf(int command, const deque<int>& dq)
{
	for (int i = 0; i < dq.size(); ++i)
	{
		if (command == dq[i])
			return i;
	}
	return -1;
}

int Solution(vector<int>& commands, deque<int>& dq)
{
	int answer = 0;

	for (int i = 0; i < m; ++i)
	{
		if (IndexOf(commands[i], dq) > dq.size() / 2)
		{
			while (dq.front() != commands[i])
			{
				int temp = dq.back();
				dq.pop_back();
				dq.push_front(temp);
				answer++;
			}

			dq.pop_front();
		}
		else
		{
			while (dq.front() != commands[i])
			{
				int temp = dq.front();
				dq.pop_front();
				dq.push_back(temp);
				answer++;
			}

			dq.pop_front();
		}
	}

	return answer;
}

int main()
{
	cin >> n >> m;

	vector<int> commands;
	deque<int> dq;

	Input(commands, dq);

	cout << Solution(commands, dq);
}
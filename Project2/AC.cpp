#include <iostream>
#include <deque>
#include <string>
using namespace std;

void Testcase(int, int);

int main()
{
	int tcCount;
	cin >> tcCount;

	for (int i = 0; i < tcCount; ++i)
	{
		Testcase(i, tcCount);
	}
}

void Testcase(int tcNum, int totalTc)
{
	string result = "";
	string p;
	int n;
	bool isRev = false;
	string arr;
	cin >> p;
	cin >> n;
	cin >> arr;

	deque<int> dq;
	string str = "";

	for (int i = 0; i < arr.size(); ++i)
	{
		if (std::isdigit(arr[i]))
			str += arr[i];
		else
		{
			if (!str.empty())
			{
				dq.push_back(stoi(str));
				str = "";
			}
		}
	}

	for (int i = 0; i < p.size(); ++i)
	{
		if (p[i] == 'R')
		{
			isRev = !isRev;
		}
		else
		{
			if (dq.empty())
			{
				cout << "error";
				if (tcNum < totalTc - 1)
					cout << '\n';

				return;
			}

			if (isRev)
				dq.pop_back();
			else
				dq.pop_front();
		}
	}

	cout << '[';
	if (isRev)
	{
		for (int i = dq.size() - 1; i >= 0; --i)
		{
			cout << dq[i];
			if (i > 0)
				cout << ',';
			else
				cout << ']';
		}
	}
	else
	{
		for (int i = 0; i < dq.size(); ++i)
		{
			cout << dq[i];
			if (i < dq.size() - 1)
				cout << ',';
			else
				cout << ']';
		}
	}

	if (dq.size() == 0)
		cout << ']';

	if (tcNum < totalTc - 1)
		cout << '\n';
}
#include <iostream>
#include <string>
#include <vector>
#define endl '\n'
#define space ' '
using namespace std;

void solution(int number, string currentExp, int currentVal, int currentNumber)
{
	if (currentExp.size() == number * 2 - 1 && currentVal == 0)
	{
		cout << currentExp << endl;
		return;
	}

	for (int i = currentNumber + 1; i <= number; ++i)
	{
		int sz = currentExp.size();
		if (sz > 2)
		{
			int temp = currentExp[currentExp.size() - 1] - '0';
			if (currentExp[sz - 2] == '+')
			{
				solution(number, currentExp + ' ' + to_string(i), currentVal - temp + ((currentExp[currentExp.size() - 1] - '0') * 10 + i), i);
			}
			else if (currentExp[sz - 2] == '-')
			{
				solution(number, currentExp + ' ' + to_string(i), currentVal + temp - ((currentExp[currentExp.size() - 1] - '0') * 10 + i), i);
			}
		}
		else
		{
			int temp = currentExp[currentExp.size() - 1] - '0';
			solution(number, currentExp + ' ' + to_string(i), currentVal - temp + ((currentExp[currentExp.size() - 1] - '0') * 10 + i), i);
		}
		solution(number, currentExp + '+' + to_string(i), currentVal + i, i);
		solution(number, currentExp + '-' + to_string(i), currentVal - i, i);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int number;
		cin >> number;
		solution(number, "1", 1, 1);
		cout << endl;
	}
}
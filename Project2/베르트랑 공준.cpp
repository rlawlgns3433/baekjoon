#include <iostream>
#include <vector>
using namespace std;

vector<bool> v(123456 * 2 + 1, true);

void PreProcess()
{
	v[1] = false;
	for (int i = 2; i * i <= 123456 * 2; ++i)
	{
		if (v[i])
		{
			for (int j = i * i; j <= 123456 * 2; j += i)
			{
				v[j] = false;
			}
		}
	}
	v[2] = true;
}

int Solution(int number)
{
	int count = 0;
	int size = min(2 * number, 123456 * 2);
	for (int i = number + 1; i <= size; ++i)
	{
		if (v[i])
			count++;
	}
	return count;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int number;
	PreProcess();
	while (true)
	{
		cin >> number;
		if (number == 0)
			break;

		cout << Solution(number) << '\n';
	}
}
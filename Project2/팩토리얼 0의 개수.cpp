#include <iostream>
#include <cmath>
using namespace std;

int divide_by_2, divide_by_5;

void factorize(int n)
{
	int _divide_by_2 = 0, _divide_by_5 = 0;
	while (n % 2 == 0)
	{
		_divide_by_2++;
		n /= 2;
	}

	while (n % 5 == 0)
	{
		_divide_by_5++;
		n /= 5;
	}
	if (n == 2) _divide_by_2++;
	if (n == 5) _divide_by_5++;

	divide_by_2 += _divide_by_2;
	divide_by_5 += _divide_by_5;
}

void process(int n)
{
	for (int i = 1; i <= n; i++)
	{
		factorize(i);
	}
	if (divide_by_2 == 0 || divide_by_5 == 0)
	{
		cout << 0;
		exit(0);
	}
	if (divide_by_2 == divide_by_5)
		cout << divide_by_2;
	else {
		int m = min(divide_by_2, divide_by_5);
		cout << m;
	}
}

int main()
{
	int n;
	cin >> n;

	process(n);
	return 0;
}
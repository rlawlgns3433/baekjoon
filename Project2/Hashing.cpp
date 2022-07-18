#include <iostream>
#include <string>
#include <cmath>
using namespace std;

long long my_pow(long long r, long long i)
{
	if (i == 0) return 1;
	else return r * my_pow(r, i - 1) % 1234567891;
}

long long change_number(char c)
{
	return c - 96;
}

long long process(long long n, string str)
{
	long long M = 1234567891;
	long long sum = 0;
	for (long long i = 0; i < n; i++)
	{
		long long number = change_number(str[i]);
		number = number * my_pow(31, i);
		number %= M;
		sum += number;
	}
	return sum % M;
}

int main()
{
	string str;
	long long n;
	cin >> n >> str;

	long long answer = process(n, str);
	cout << answer << '\n';
}
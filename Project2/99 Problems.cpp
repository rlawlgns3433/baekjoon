#include <iostream>
using namespace std;

int solution(int n)
{
	int answer = 0;

	if (n < 100)
		return 99;

	int rem = n % 100;
	if (rem == 99)
		return n;

	answer = 100 - rem;

	if (answer == 100)
		return n - 1;

	if (rem >= 49)
	{
		answer = n + answer - 1;
	}
	else
	{
		answer = n - rem - 1;
	}

	return answer;
}

int main()
{
	int number;
	cin >> number;

	cout << solution(number);
}
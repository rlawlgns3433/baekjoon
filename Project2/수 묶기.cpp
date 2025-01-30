#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

enum class numType
{
	POSITIVE = 1 << 1,
	NEGATIVE = 1 << 2
};

int rem = 0;
vector<int> v_positive, v_negative;

int solution(const vector<int>& v, int n)
{
	int sum = 0;
	int i;
	for (i = 0; i < n - 1; i += 2)
	{
		int mul = v[i] * v[i + 1];
		int add = v[i] + v[i + 1];

		if (mul > add)
		{
			sum += mul;
		}
		else
		{
			sum += add;
		}
	}

	if (i == n - 1)
	{
		sum += v[i];
	}

	return sum;
}

int main()
{
	int n;
	cin >> n;
	int number;
	for (int i = 0; i < n; ++i)
	{
		cin >> number;
		if (number > 0)
			v_positive.push_back(number);
		else
			v_negative.push_back(number);

		if (n == 1)
		{
			cout << number;
			return 0;
		}
	}

	sort(v_positive.begin(), v_positive.end(), [](int lhs, int rhs) {return lhs > rhs; });
	sort(v_negative.begin(), v_negative.end(), [](int lhs, int rhs) {return lhs < rhs; });


	int pos = solution(v_positive, v_positive.size());
	int neg = solution(v_negative, v_negative.size());

	cout << pos + neg;
}
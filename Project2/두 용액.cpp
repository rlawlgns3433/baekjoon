#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#define INT_MAX 2147483647
using namespace std;

enum Sign {
	pos = 1, neg = 0
};

class Solution
{
public:
	bool b;
	int val;

	Solution(int val, bool b)
	{
		this->val = val;
		this->b = b;
	}

	bool getCode()
	{
		return b;
	}
};

bool compare(const Solution& sol1, const Solution& sol2)
{
	return abs(sol1.val) < abs(sol2.val);
}

int main()
{
	int n;
	cin >> n;

	vector<Solution> solutions;

	for (int i = 0; i < n; i++)
	{
		int va;
		cin >> va;
		if (va >= 0)
		{
			Solution s = Solution(va, pos);
			solutions.push_back(s);
		}
		else
		{
			Solution s = Solution(va, neg);
			solutions.push_back(s);
		}
	}

	sort(solutions.begin(), solutions.end(), compare);

	int mn = INT_MAX;
	int n1 = 0, n2 = 0;
	for (int i = 0; i < n - 1; i++)
	{
		if (solutions[i].getCode() != solutions[i + 1].getCode())
		{
			int diff = abs(abs(solutions[i].val) - abs(solutions[i + 1].val));
			if (diff < mn)
			{
				mn = diff;
				n1 = solutions[i].val;
				n2 = solutions[i + 1].val;
			}
		}
		else
		{
			int ad = abs(solutions[i].val + solutions[i + 1].val);
			if (ad < mn)
			{
				mn = ad;
				n1 = solutions[i].val;
				n2 = solutions[i + 1].val;
			}
		}
	}

	if (n1 <= n2)
	{
		cout << n1 << ' ' << n2 << endl;
	}
	cout << n2 << ' ' << n1 << endl;



	//for (auto a : solutions)
	//{
	//	cout << a.val << ":" << a.b << endl;
	//}
}
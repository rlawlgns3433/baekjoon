#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	vector<int> multiples(m);
	vector<int> singles(m);

	for (int i = 0; i < m; ++i)
	{
		cin >> multiples[i] >> singles[i];
	}

	sort(multiples.begin(), multiples.end());
	sort(singles.begin(), singles.end());

	int multipleCount = n / 6;
	int singleCount = n % 6;

	if (multiples[0] > singles[0] * 6)
	{
		singleCount += multipleCount * 6;
		multipleCount = 0;
	}
	else if (singleCount * singles[0] > multiples[0])
	{
		singleCount = 0;
		multipleCount++;
	}

	cout << multipleCount * multiples[0] + singleCount * singles[0];
}
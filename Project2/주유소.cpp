#include <iostream>
#include <vector>	
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long n;
	vector<long long> dist;
	vector<long long> oilbank;

	cin >> n;

	long long distIndex = 0;
	long long currentPosition = 0;
	long long totalCost = 0;
	long long minOilBankIndex = 0;

	for (long long i = 0; i < n - 1; ++i)
	{
		long long r;
		cin >> r;
		dist.push_back(r);
	}

	for (long long i = 0; i < n; ++i)
	{
		long long o;
		cin >> o;
		oilbank.push_back(o);
	}

	while (true)
	{
		if (distIndex == n - 1)
			break;

		if (oilbank[minOilBankIndex] > oilbank[currentPosition])
			minOilBankIndex = currentPosition;

		totalCost += dist[distIndex] * oilbank[minOilBankIndex];
		distIndex++;
		currentPosition++;
	}

	cout << totalCost;
}
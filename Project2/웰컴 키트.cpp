#include <iostream>
#include <vector>
using namespace std;

int N;
int T, P;
vector<int> v;

int main()
{
	cin >> N;
	v.resize(6);

	int max = 0;

	for (int i = 0; i < 6; ++i)
	{
		cin >> v[i];
	}

	cin >> T >> P;
	int count = 0;
	for (int i = 0; i < 6; ++i)
	{
		if (v[i] / T == 0)
		{
			if (v[i] % T == 0)
				continue;
			count += 1;
		}
		else

		{
			count += v[i] / T;
			if (v[i] % T == 0)
				continue;
			count += 1;
		}
	}

	cout << count << endl;
	cout << N / P << ' ' << N % P;
}
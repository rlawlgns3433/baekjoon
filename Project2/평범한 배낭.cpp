#include <iostream>
#include <vector>
using namespace std;

// n : 물품의 수, k : 배낭에 담을 수 있는 최대 무게
int n, k;
vector<vector<int>> knap;
vector<int> weights, values;

int knapsack()
{
	for (int i = 1; i <= n; i++) // 물건 번호
	{
		for (int j = 1; j <= k; j++) // 임시 무게
		{
			if (weights[i] > j) knap[i][j] = knap[i - 1][j];
			else
			{
				knap[i][j] = max(knap[i - 1][j], knap[i - 1][j - weights[i]] + values[i]);
			}
		}
	}
	return knap[n][k];
}

int main()
{
	cin >> n >> k;
	knap.resize(n + 1, vector<int>(100001));
	weights.resize(n + 1);
	values.resize(n + 1);

	for (int i = 0; i <= n; i++) // 용량이 0일 때
	{
		knap[i][0] = 0;
	}

	for (int i = 0; i <= k; i++) // 물건의 개수가 0일 떄
	{
		knap[0][i] = 0;
	}
	weights.push_back(0);
	values.push_back(0);
	for (int i = 1; i <= n; i++)
	{
		int weight, value;
		cin >> weight >> value;
		knap[i][weight] = value;
		weights[i] = weight;
		values[i] = value;
	}

	cout << knapsack();
}
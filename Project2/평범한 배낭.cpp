#include <iostream>
#include <vector>
using namespace std;

// n : ��ǰ�� ��, k : �賶�� ���� �� �ִ� �ִ� ����
int n, k;
vector<vector<int>> knap;
vector<int> weights, values;

int knapsack()
{
	for (int i = 1; i <= n; i++) // ���� ��ȣ
	{
		for (int j = 1; j <= k; j++) // �ӽ� ����
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

	for (int i = 0; i <= n; i++) // �뷮�� 0�� ��
	{
		knap[i][0] = 0;
	}

	for (int i = 0; i <= k; i++) // ������ ������ 0�� ��
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
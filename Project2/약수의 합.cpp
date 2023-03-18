#include <iostream>
#include <vector>
using namespace std;

const int mx = 1000001;

vector<long long> dp(mx + 1, 1);
vector<long long> answers(mx + 1, 1);

// �����佺�׳׽��� ü �˰������� ��� ���ϱ�
void sumDivisor()
{
	for (int i = 2; i <= mx; i++)
	{
		for (int j = 1; i * j <= mx; j++)
		{
			dp[i * j] += i;
		}
	}
}

int main()
{

	ios::sync_with_stdio(0); cout.tie(0), cin.tie(0);

	int n, mx = 0;
	int num;

	cin >> n;

	vector<int> numbers(n + 1);

	sumDivisor();

	int mxnum = 0;

	// �Է��� �ִ밪 ���ϱ�
	for (int i = 0; i < n; i++)
	{
		cin >> numbers[i];
		mxnum = numbers[i] > mxnum ? numbers[i] : mxnum;
	}

	// �ִ밪���� ������� �� ���ϱ�
	for (int i = 2; i <= mxnum; i++)
	{
		answers[i] = answers[i - 1] + dp[i];
	}

	// �Էµ� ���ڱ����� ������� �� ���
	for (int i = 0; i < n; i++)
	{
		cout << answers[numbers[i]] << '\n';
	}
}
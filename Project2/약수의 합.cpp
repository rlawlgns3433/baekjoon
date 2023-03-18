#include <iostream>
#include <vector>
using namespace std;

const int mx = 1000001;

vector<long long> dp(mx + 1, 1);
vector<long long> answers(mx + 1, 1);

// 에라토스테네스의 체 알고리즘으로 약수 구하기
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

	// 입력의 최대값 구하기
	for (int i = 0; i < n; i++)
	{
		cin >> numbers[i];
		mxnum = numbers[i] > mxnum ? numbers[i] : mxnum;
	}

	// 최대값까지 약수들의 합 구하기
	for (int i = 2; i <= mxnum; i++)
	{
		answers[i] = answers[i - 1] + dp[i];
	}

	// 입력된 숫자까지의 약수들의 합 출력
	for (int i = 0; i < n; i++)
	{
		cout << answers[numbers[i]] << '\n';
	}
}
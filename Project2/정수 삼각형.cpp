#include <iostream>
#include <memory>
#include <vector>
#define fastio (ios::sync_with_stdio(0), cin.tie(0))
using namespace std;

int main()
{
	fastio;
	// n : 삼각형의 높이
	int n;
	cin >> n;

	/// <summary>
	/// arr : 삼각형 배열
	/// answer : 정답 배열
	/// </summary>
	vector<vector<int>> arr, answer;

	arr.resize(n, vector<int>(n)); // 배열 크기 할당
	answer.resize(n, vector<int>(n)); // 배열 크기 할당

	// 삼각형 배열 원소 입력
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cin >> arr[i][j];
		}
	}

	// Bottom Up 방식을 이용하기 위한 최하위 원소들 지정
	for (int i = 0; i < n; i++)
	{
		answer[n - 1][i] = arr[n - 1][i];
	}

	// Bottom Up 방식으로 최대값을 결정
	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = 1; j <= i; j++)
		{
			int mx = max(answer[i][j - 1], answer[i][j]); // 원소 두 개씩 비교하며 최대값을 찾음
			answer[i - 1][j - 1] = arr[i - 1][j - 1] + mx; // 위에서 찾은 최대값을 바로 위 원소와 더하여 정답 배열에 저장 (최대값을 찾아가는 과정)
		}
	}
	cout << answer[0][0]; // 최종적으로 최상위에 있는 원소가 최대값
}
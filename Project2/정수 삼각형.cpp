#include <iostream>
#include <memory>
#include <vector>
#define fastio (ios::sync_with_stdio(0), cin.tie(0))
using namespace std;

int main()
{
	fastio;
	// n : �ﰢ���� ����
	int n;
	cin >> n;

	/// <summary>
	/// arr : �ﰢ�� �迭
	/// answer : ���� �迭
	/// </summary>
	vector<vector<int>> arr, answer;

	arr.resize(n, vector<int>(n)); // �迭 ũ�� �Ҵ�
	answer.resize(n, vector<int>(n)); // �迭 ũ�� �Ҵ�

	// �ﰢ�� �迭 ���� �Է�
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cin >> arr[i][j];
		}
	}

	// Bottom Up ����� �̿��ϱ� ���� ������ ���ҵ� ����
	for (int i = 0; i < n; i++)
	{
		answer[n - 1][i] = arr[n - 1][i];
	}

	// Bottom Up ������� �ִ밪�� ����
	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = 1; j <= i; j++)
		{
			int mx = max(answer[i][j - 1], answer[i][j]); // ���� �� ���� ���ϸ� �ִ밪�� ã��
			answer[i - 1][j - 1] = arr[i - 1][j - 1] + mx; // ������ ã�� �ִ밪�� �ٷ� �� ���ҿ� ���Ͽ� ���� �迭�� ���� (�ִ밪�� ã�ư��� ����)
		}
	}
	cout << answer[0][0]; // ���������� �ֻ����� �ִ� ���Ұ� �ִ밪
}
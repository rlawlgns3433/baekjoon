// �ذ� ���̵��
// 1. 30�� ����̹Ƿ� ������ �ڸ����� 0�̴�
// 2. �� �ڸ������� ���� ���� 3���� ������ �������� �Ѵ�.

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string num;
int main()
{
	cin >> num;

	sort(num.rbegin(), num.rend());
	if (num[num.size() - 1] != '0') cout << -1;
	else
	{
		int sum = 0;
		for (int i = 0; i < num.size(); i++)
		{
			sum += num[i];
		}
		if (sum % 3 == 0) cout << num;
		else cout << -1;
	}

}

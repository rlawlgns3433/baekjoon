// 해결 아이디어
// 1. 30의 배수이므로 마지막 자리수가 0이다
// 2. 각 자리수들을 더한 값이 3으로 나누어 떨어져야 한다.

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

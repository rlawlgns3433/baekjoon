#include <iostream>
#include <string>
using namespace std;

string str;
int main()
{
	cin >> str;

	int answer = 0;
	string num;
	bool isMinus = false;

	for (int i = 0; i <= str.size(); i++)
	{
		if (str[i] == '-' || str[i] == '+' || i == str.size()) // -, + 또는 마지막 숫자일 때
		{
			if (isMinus) // - 기호가 이미 나온 상태라면
			{
				answer -= stoi(num); // 현재항의 숫자의 절대값을 빼준다.
				num = ""; // 현재항을 초기화
			}
			else
			{
				answer += stoi(num); // - 기호가 나오지 않은 상태라면 값을 더해준다.
				num = ""; // 현재항을 초기화
			}
		}
		else // 마지막이 아닌 숫자일 때 (숫자의 부호는 X)
		{
			num += str[i]; // 현재항의 절대값을 만든다.
		}

		if (str[i] == '-') // - 기호를 만나면 앞으로 나올 항의 절대값만 빼주면 된다.
		{
			isMinus = true;
		}
	}
	cout << answer;
}
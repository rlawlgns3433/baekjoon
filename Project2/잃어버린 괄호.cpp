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
		if (str[i] == '-' || str[i] == '+' || i == str.size()) // -, + �Ǵ� ������ ������ ��
		{
			if (isMinus) // - ��ȣ�� �̹� ���� ���¶��
			{
				answer -= stoi(num); // �������� ������ ���밪�� ���ش�.
				num = ""; // �������� �ʱ�ȭ
			}
			else
			{
				answer += stoi(num); // - ��ȣ�� ������ ���� ���¶�� ���� �����ش�.
				num = ""; // �������� �ʱ�ȭ
			}
		}
		else // �������� �ƴ� ������ �� (������ ��ȣ�� X)
		{
			num += str[i]; // �������� ���밪�� �����.
		}

		if (str[i] == '-') // - ��ȣ�� ������ ������ ���� ���� ���밪�� ���ָ� �ȴ�.
		{
			isMinus = true;
		}
	}
	cout << answer;
}
#include <iostream>
using namespace std;

// �Ľ�Į �ﰢ���� �̿��Ͽ� ����
// nCr = n-1Cr + n-1Cr-1;
int combination(int n, int r)
{
    if (n == r || r == 0) // nCn �Ǵ� nC0�� 1�̱� ������ ����� ���� ����
        return 1;
    else return combination(n - 1, r - 1) + combination(n - 1, r);
}

int main()
{
    int n, r;
    cin >> n >> r;
    cout << combination(n, r);
}
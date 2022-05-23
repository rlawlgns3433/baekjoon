#include <iostream>
using namespace std;

// 파스칼 삼각형을 이용하여 구함
// nCr = n-1Cr + n-1Cr-1;
int combination(int n, int r)
{
    if (n == r || r == 0) // nCn 또는 nC0은 1이기 때문에 재귀의 종료 조건
        return 1;
    else return combination(n - 1, r - 1) + combination(n - 1, r);
}

int main()
{
    int n, r;
    cin >> n >> r;
    cout << combination(n, r);
}
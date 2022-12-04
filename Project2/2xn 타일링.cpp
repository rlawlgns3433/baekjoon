#include <iostream>
using namespace std;

int arr[1001];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;

    arr[0] = arr[1] = 1;

    for (int i = 2; i <= 1001; i++)
    {
        arr[i] = (arr[i - 2] + arr[i - 1]) % 10007;
    }
    cout << arr[n];
}
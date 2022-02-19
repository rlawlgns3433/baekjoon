#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int arr[10] = { 0 };
    int n;
    cin >> n;
    while (true) {
        arr[n % 10]++;
        if (n / 10 == 0) break;
        n /= 10;
    }
    int set = 0;
    for (int i = 0; i < 10; i++) {
        if (i != 9 && i != 6)
            set = max(set, arr[i]);
    }
    cout << max(set, (arr[6] + arr[9] + 1) / 2);
}
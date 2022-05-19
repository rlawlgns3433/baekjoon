#include <iostream>
using namespace std;

long long gcd(long long a, long long b)
{
    int temp;
    if (a < b)
    {
        temp = a;
        a = b;
        b = temp;
    }
    int c = 0;
    while (a % b)
    {
        c = a % b;
    }
    return c;
}

int main()
{
    long long a, b;
    cin >> a >> b;

    cout << gcd(a, b);
}
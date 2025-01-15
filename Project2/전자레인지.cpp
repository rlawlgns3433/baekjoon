#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;

    int min5 = 0;
    int min1 = 0;
    int sec10 = 0;

    if (t / 300 > 0)
    {
        min5 = t / 300;
        t = t % 300;
    }

    if (t / 60 > 0)
    {
        min1 = t / 60;
        t = t % 60;
    }

    if (t / 10 > 0)
    {
        sec10 = t / 10;
        t = t % 10;
    }

    if (t > 0)
        cout << -1;
    else
        cout << min5 << ' ' << min1 << ' ' << sec10;
}
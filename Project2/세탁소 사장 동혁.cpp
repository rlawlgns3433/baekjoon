#include <iostream>
using namespace std;

void Solution(int changes)
{
    int q = 0;
    int d = 0;
    int n = 0;
    int p = 0;

    if (changes >= 25)
    {
        q += changes / 25;
        changes %= 25;
    }

    if (changes >= 10)
    {
        d += changes / 10;
        changes %= 10;
    }

    if (changes >= 5)
    {
        n += changes / 5;
        changes %= 5;
    }

    cout << q << ' ' << d << ' ' << n << ' ' << changes;
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        int input;
        cin >> input;
        Solution(input);
        if (i < n - 1)
        {
            cout << '\n';
        }
    }
}
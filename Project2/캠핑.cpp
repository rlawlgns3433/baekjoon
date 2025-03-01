#include <iostream>
#include <cmath>
using namespace std;

void Solution(int n, int l, int p, int v)
{
    int answer = 0;

    int tmp = v / p;
    answer = l * tmp;
    v -= p * tmp;
    answer += min(v, l);

    cout << "Case " << n << ": " << answer << '\n';
}

int main()
{
    int l, p, v;
    int count = 1;
    while (true)
    {
        cin >> l >> p >> v;
        if (l == 0 && p == 0 && v == 0)
            break;

        Solution(count++, l, p, v);
    }
}
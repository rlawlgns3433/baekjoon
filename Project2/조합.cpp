#include <iostream>
using namespace std;

string uint128ToString(__uint128_t num)
{
    string result;
    while (num > 0)
    {
        result = char('0' + (num % 10)) + result;
        num /= 10;
    }

    return result.empty() ? "0" : result;
}

ostream& operator<< (ostream& os, __uint128_t i)
{
    os << uint128ToString(i);
    return os;
}

int main()
{
    int n, m;
    cin >> n >> m;

    __uint128_t answer = 1;
    int r = 1;

    for (int i = n; i > n - m; --i)
    {
        answer = answer * i;
        answer = answer / r;
        r++;
    }

    cout << answer;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int n;
vector<int> v(26, 0);

void CalcStringValue(const string str)
{
    int size = str.size();
    int p = 0;
    for (int i = size - 1; i >= 0; --i)
    {
        v[str[i] - 65] += pow(10, p++);
    }
}

void Input()
{
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        string str;
        cin >> str;
        CalcStringValue(str);
    }
}

int main()
{
    Input();
    sort(v.begin(), v.end(),
        [](int lhs, int rhs)
        {return lhs > rhs; });

    int sum = 0;
    int d = 9;

    for (int i = 0; i < 26; ++i)
    {
        if (v[i] == 0)
            break;

        sum += v[i] * d--;
    }

    cout << sum;
}
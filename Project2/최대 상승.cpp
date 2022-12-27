#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v;
    v.resize(n);

    int min;
    cin >> min;
    v[0] = min;

    int benefit = 0;

    for (int i = 1; i < n; i++)
    {
        cin >> v[i];
        if (v[i] >= min)
        {
            benefit = max(benefit, v[i] - min);
        }
        else min = v[i];
    }
    cout << benefit;
}
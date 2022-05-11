#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> times;
    int n, temp = 0;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        times.emplace_back(temp);
    }

    sort(times.begin(), times.end());

    int used_time = times[0];
    v.emplace_back(used_time);
    for (int i = 1; i < n; i++)
    {
        used_time += times[i];
        v.emplace_back(used_time);
    }
    int sum = 0;
    for (auto& e : v)
    {
        sum += e;
    }
    cout << sum;
}
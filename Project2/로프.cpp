#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v;
int N;

int main()
{
    cin >> N;
    v.resize(N);
    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    int min_value = 0;
    for (int i = 0; i < v.size(); i++)
    {
        int right = v[i] * (v.size() - i);
        if (min_value < right) min_value = right;
    }
    cout << min_value;
}
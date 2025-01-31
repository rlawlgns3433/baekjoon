#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> v;
    vector<int> answer;
    v.resize(n, vector<int>(3));

    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> v[j][i];
        }
    }
    for (int i = 0; i < n; ++i)
    {
        sort(v[i].begin(), v[i].end());

        cout << v[i][1] << ' ';
    }
}
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


bool compare(pair<int, int> lhs, pair<int, int> rhs)
{
    return lhs.second < rhs.second;
}

int main()
{
    vector<pair<int, int>> v(8);

    for (int i = 0; i < 8; ++i)
    {
        int score;
        cin >> score;

        v[i] = make_pair(score, i + 1);
    }

    sort(v.rbegin(), v.rend());

    int sum = 0;
    vector<pair<int, int>> rank;
    for (int i = 0; i < 5; ++i)
    {
        sum += v[i].first;
        rank.push_back(v[i]);
    }

    cout << sum << '\n';
    sort(rank.begin(), rank.end(), compare);

    for (int i = 0; i < 5; ++i)
    {
        cout << rank[i].second;
        if (i < 4)
            cout << ' ';
    }
}
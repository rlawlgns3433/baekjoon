#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;

    queue<int> q;
    vector<int> order;
    for (int i = 1; i <= n; i++)
    {
        q.push(i);
    }

    while (!q.empty())
    {
        for (int i = 0; i < m - 1; i++)
        {
            int k = q.front();
            q.pop();
            q.push(k);
        }
        order.emplace_back(q.front());
        q.pop();
    }

    cout << '<';
    for (int i = 0; i < n; i++)
    {
        cout << order[i];
        if (i < n - 1)
            cout << ", ";
    }
    cout << '>';
}
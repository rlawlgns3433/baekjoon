#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> v(9);
vector<bool> visited(9);

void dfs(int num, int cnt)
{
    if (cnt == m)
    {
        for (int i = 0; i < m; ++i)
        {
            cout << v[i] << ' ';
        }
        cout << '\n';
    }

    for (int i = num; i <= n; ++i)
    {
        if (!visited[i])
        {
            visited[i] = true;
            v[cnt] = i;
            dfs(i + 1, cnt + 1);
            visited[i] = false;
        }
    }
}

int main()
{
    cin >> n >> m;
    dfs(1, 0);
}
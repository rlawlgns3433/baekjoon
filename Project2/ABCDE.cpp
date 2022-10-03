#include <iostream>
#include <vector>
#include <memory.h>
#define fastio (cin.tie(0), cout.tie(0), ios::sync_with_stdio(0))
using namespace std;

int n, m;
vector<int> f_map[2000];
bool visited[2000];
int isEnd = 0;

void dfs(int start, int cur_cnt)
{
    if (cur_cnt > 3)
    {
        isEnd = 1;
        return;
    }
    visited[start] = true;

    for (int i = 0; i < f_map[start].size(); i++)
    {
        if (!visited[f_map[start][i]])
        {
            dfs(f_map[start][i], cur_cnt + 1);
        }
        if (isEnd) return;
    }
    visited[start] = false;
}

int main()
{
    fastio;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        f_map[x].emplace_back(y);
        f_map[y].emplace_back(x);
    }

    for (int i = 0; i < n; i++)
    {
        memset(visited, false, sizeof(visited));
        dfs(i, 0);
        if (isEnd) break;
    }

    cout << isEnd;
}
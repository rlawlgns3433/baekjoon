#include <iostream>
#include <queue>
#include <vector>
#define MAX_COMPUTER 101
using namespace std;

vector<vector<int>> c_map;
queue<int> q;
int n, m, start;
bool visited[MAX_COMPUTER] = { 0, };
void bfs(int start)
{
    visited[start] = true;
    q.push(start);
    int cnt = 0;
    while (!q.empty())
    {
        int computer = q.front();
        q.pop();

        for (int i = 1; i <= n; i++)
        {
            if (c_map[computer][i] == 1 && !visited[i])
            {
                visited[i] = true;
                q.push(i);
                cnt++;
            }
        }
    }
    cout << cnt;
}

int main()
{
    cin >> n >> m;
    c_map.resize(n + 1, vector<int>(n + 1));

    for (int i = 0; i < m; i++)
    {
        int src, dst;
        cin >> src >> dst;
        c_map[src][dst] = c_map[dst][src] = 1;
    }

    bfs(1);
}
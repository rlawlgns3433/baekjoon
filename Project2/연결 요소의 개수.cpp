#include <iostream>
#include <queue>
using namespace std;

queue<int> q;
int maps[1001][1001];
bool visited[1001];
int num, edge_num, linked_element;

void init(int num)
{
    for (int i = 1; i <= num; i++)
    {
        for (int j = 1; j <= num; j++)
            maps[i][j] = 0;
    }
    for (int i = 1; i <= num; i++)
    {
        visited[i] = 0;
    }
}

void bfs(int start)
{
    visited[start] = true;
    q.push(start);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (int i = 1; i <= num; i++)
        {
            if (maps[node][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                q.push(i);
            }
        }
    }
}

int main()
{
    cin >> num >> edge_num;
    init(num);
    int v1, v2;
    for (int i = 0; i < edge_num; i++)
    {
        cin >> v1 >> v2;
        maps[v1][v2] = maps[v2][v1] = 1;
    }

    for (int i = 1; i <= num; i++)
    {
        if (visited[i] == 0)
        {
            linked_element++;
            bfs(i);
        }
    }
    cout << linked_element;
}
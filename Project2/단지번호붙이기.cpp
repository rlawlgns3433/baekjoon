#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<int>> complex, visited;
int n;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int complex_num = 0;
int cnt_complex[25 * 25] = { 0, };

void bfs(int x, int y)
{
    queue<pair<int, int>> q;
    q.push({ x,y });
    visited[x][y] = 1;
    cnt_complex[complex_num]++;

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;

        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

            if (complex[nx][ny] == 0) continue;

            if (complex[nx][ny] == 1 && visited[nx][ny] == false)
            {
                cnt_complex[complex_num]++;
                q.push({ nx, ny });
                visited[nx][ny] = true;
            }
        }
    }
}
int main()
{

    cin >> n;
    complex.resize(n, vector<int>(n));
    visited.resize(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%1d", &complex[i][j]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (complex[i][j] == 1 && visited[i][j] == false)
            {
                complex_num++;
                bfs(i, j);
            }
        }
    }

    sort(cnt_complex + 1, cnt_complex + complex_num + 1);
    cout << complex_num << '\n';
    for (int i = 1; i <= complex_num; i++)
    {
        cout << cnt_complex[i] << '\n';
    }
}
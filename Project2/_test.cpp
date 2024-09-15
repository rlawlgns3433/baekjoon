#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N, M, K, X;
    cin >> N >> M >> K >> X;
    vector<int> dist(N + 1, 100000000);
    vector<vector<int>> mp(N + 1, vector<int>(N + 1, 100000000));

    for (int i = 0; i < M; ++i)
    {
        int src, dst;
        cin >> src >> dst;
        mp[src][dst] = 1;
    }

    dist[X] = 0;
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            if (i == j)
                continue;

            if (mp[i][j] < 100000000)
            {
                if(dist[i] == 100000000)
                    dist[i] = 0;

                int temp = dist[i] + mp[i][j];
                if (dist[j] > temp)
                {
                    dist[j] = temp;
                }
            }
        }
    }

    for (int i = 0; i < dist.size(); ++i)
    {
        if(dist[i] == K)
			cout << i << '\n';
        return 0;
    }
    cout << -1;
    return 0;
}

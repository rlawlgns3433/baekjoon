#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    vector<vector<int>> dp;
    cin >> N >> M;

    dp.resize(N + 1, vector<int>(N + 1));

    for (int i = 1; i <= N; ++i)
    {
        int sum = 0;
        for (int j = 1; j <= N; ++j)
        {
            int number;
            cin >> number;

            sum += number;
            dp[i][j] = sum;
        }
    }

    for (int i = 0; i < M; ++i)
    {
        int startRow, startCol, endRow, endCol;
        cin >> startRow >> startCol >> endRow >> endCol;
        int sum = 0;
        for (int j = startRow; j <= endRow; ++j)
        {
                sum += dp[j][endCol] - dp[j][startCol - 1];
        }

        cout << sum << '\n';
    }
}
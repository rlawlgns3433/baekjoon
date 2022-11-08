#include <iostream>
#define fastio (cin.tie(0), cout.tie(0), ios::sync_with_stdio(0))
using namespace std;

int dp[15][15];

void dp_f()
{
    for (int i = 1; i <= 14; i++)
    {
        dp[0][i] = i;
    }

    for (int i = 1; i <= 14; i++)
    {
        for (int j = 1; j <= 14; j++)
        {
            dp[i][j] += dp[i][j - 1] + dp[i - 1][j];
        }
    }
}

void testcase()
{
    int k, n;
    cin >> k >> n;

    cout << dp[k][n] << endl;
}

int main()
{
    fastio;
    int T;
    cin >> T;
    dp_f();

    for (int i = 0; i < T; i++)
    {
        testcase();
    }

}
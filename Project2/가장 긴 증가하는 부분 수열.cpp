#include <iostream>
#include <vector>
using namespace std;

vector<int> dp(1001, 1);
vector<int> arr;
int n;

int main()
{
    int n, LIS = 1;
    cin >> n;
    dp.resize(n + 1);
    arr.resize(n + 1);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        dp[i] = 1;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i])
            {
                if (dp[j] + 1 > dp[i])
                {
                    dp[i] = dp[j] + 1;
                }

                if (LIS < dp[i])
                    LIS = dp[i];
            }
        }
    }
    cout << LIS;
}
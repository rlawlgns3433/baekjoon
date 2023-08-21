#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, k;
vector<int> dp;
vector<int> parent;
queue<int> q;

void bfs(int start, int target) {
    q.push(start);
    dp[start] = 0;

    while (!q.empty()) {
        int x = q.front();
        q.pop();

        if (x == target) {
            break;
        }

        if (x - 1 >= 0 && dp[x - 1] == -1) {
            q.push(x - 1);
            dp[x - 1] = dp[x] + 1;
            parent[x - 1] = x;
        }
        if (x + 1 <= 100000 && dp[x + 1] == -1) {
            q.push(x + 1);
            dp[x + 1] = dp[x] + 1;
            parent[x + 1] = x;
        }
        if (2 * x <= 100000 && dp[2 * x] == -1) {
            q.push(2 * x);
            dp[2 * x] = dp[x] + 1;
            parent[2 * x] = x;
        }
    }
}

int main() {
    cin >> n >> k;
    dp.assign(100001, -1);
    parent.assign(100001, -1);

    bfs(n, k);

    cout << dp[k] << '\n';

    vector<int> path;
    int current = k;
    while (current != -1) {
        path.push_back(current);
        current = parent[current];
    }

    for (int i = path.size() - 1; i >= 0; --i) {
        cout << path[i] << ' ';
    }

    return 0;
}

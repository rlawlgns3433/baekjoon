#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    multiset<string> found;
    set<string> S;
    string str;
    for (int i = 0; i < n; i++) {
        cin >> str;
        S.emplace(str);
    }
    for (int i = 0; i < m; i++) {
        cin >> str;
        if (S.find(str) != S.end())
            found.emplace(str);
    }
    cout << found.size();
}

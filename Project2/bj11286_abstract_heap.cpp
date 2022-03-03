#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

bool compare(pair<int, int>& a, pair<int, int>& b) {
    if (a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}

void my11286()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    vector<pair<int, int>> p;
    for (int i = 0; i < T; i++) {
        int n; cin >> n;
        if (n == 0) {
            if (p.empty()) cout << 0 << '\n';
            else {
                cout << p.front().first << '\n';
                p.erase(p.begin());
            }
        }
        else {
            p.emplace_back(n, abs(n));
        }
        sort(p.begin(), p.end(), compare);
    }
    
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    priority_queue<int, vector<int>, greater<int>> min_heap;
    priority_queue<int> max_heap;
    int T; cin >> T;
    for (int i = 0; i < T; i++) {
        int x; cin >> x;
        if (x != 0) {
            if (x > 0) min_heap.emplace(x);
            else max_heap.emplace(x);
        }
        else if(x == 0){
            if (min_heap.empty() && max_heap.empty()) cout << 0 << '\n';
            else if (min_heap.empty()) {
                cout << max_heap.top() << '\n';
                max_heap.pop();
            }
            else if (max_heap.empty()) {
                cout << min_heap.top() << '\n';
                min_heap.pop();
            }
            else {
                if (min_heap.top() < -max_heap.top()) {
                    cout << min_heap.top() << '\n';
                    min_heap.pop();
                }
                else {
                    cout << max_heap.top() << '\n';
                    max_heap.pop();
                }
            }
        }
    }
}
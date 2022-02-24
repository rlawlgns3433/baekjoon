#include <iostream>
#include <queue>
using namespace std;

void test(priority_queue<int>& max_heap, priority_queue<int, vector<int>, greater<int>>& min_heap) {
    char type; int n; cin >> n;
    for(int i = 0;i < n; i++){
        cin >> type;
        if (type == 'I') {
            int num; cin >> num;
            max_heap.push(num); min_heap.push(num);
        }
        else if (type == 'D') {
            int num; cin >> num;
            if (num == -1) {
                cout << min_heap.top() << '\n';
                min_heap.pop();
            }
            else if (num == 1) {
                cout << max_heap.top() << '\n';
                max_heap.pop();
            }
        }
    }
    while (!min_heap.empty()) {
        cout << min_heap.top() << " ";
        min_heap.pop();
    }
    cout << endl;
    while (!max_heap.empty()) {
        cout << max_heap.top() << " ";
        max_heap.pop();
    }
}

void bj7662()
{
    cin.tie(0); cin.sync_with_stdio(0);
    int testcase; cin >> testcase;
    for (int i = 0; i < testcase; i++) {
        priority_queue<int> max_heap;
        priority_queue<int, vector<int>, greater<int>> min_heap;
        test(max_heap, min_heap);
    }
}
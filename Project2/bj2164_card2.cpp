#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<int> q1;
    int n, sw = 1;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        q1.emplace(i);
    }
    while(q1.size() != 1){
        if (sw == 1) {
            q1.pop();
            sw = 0;
        }
        else {
            q1.emplace(q1.front());
            q1.pop();
            sw = 1;
        }
    }
    cout << q1.front();
}
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

priority_queue<int, vector<int>, greater<int>> min_heap;
int acc = 0;

int main()
{
    int n;
    cin >> n;
    if (n == 1)
    {
        cout << acc;
        exit(0);
    }

    for (int i = 0; i < n; i++)
    {
        int num; cin >> num;
        min_heap.push(num);
    }

    while (min_heap.size() > 2)
    {
        int num1 = min_heap.top(); min_heap.pop();
        int num2 = min_heap.top(); min_heap.pop();

        min_heap.push(num1 + num2);
        acc += (num1 + num2);
    }
    int num1 = min_heap.top(); min_heap.pop();
    int num2 = min_heap.top();

    cout << acc + num1 + num2;
}
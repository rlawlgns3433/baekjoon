#include <iostream>
#include <queue>
#include <vector>
using namespace std;

priority_queue<int, vector<int>, greater<int>> min_heap; // 최소힙
int acc = 0; // 누적합을 저장하는 변수

int main()
{
    int n; // 카드 더미의 개수
    cin >> n;
    if (n == 1) // 더미의 개수가 1개라면 비교할 필요가 없으므로 0번 비교 후 종료
    {
        cout << acc;
        exit(0);
    }

    for (int i = 0; i < n; i++)
        // 각 카드 더미가 포함하는 카드의 개수를 입력받아 최소힙에 저장
        // 카드 개수가 적은 순서대로 저장 (그리디한 특성)
    {
        int num; cin >> num;
        min_heap.push(num);
    }

    while (min_heap.size() > 2)
        // 비교하지 않은 카드 더미의 수가 2개 보다 많다면
    {
        // 가장 작은 더미 2개를 골라 비교 횟수를 구함 ( num1 + num2 )
        int num1 = min_heap.top(); min_heap.pop(); 
        int num2 = min_heap.top(); min_heap.pop();

        min_heap.push(num1 + num2); // 카드 비교 횟수를 다시 최소힙에 저장
        acc += (num1 + num2); // 누적합을 갱신
    }

    // 최종적으로 남은 두 개의 카드 더미를 비교
    int num1 = min_heap.top(); min_heap.pop();
    int num2 = min_heap.top();

    // 정답은 마지막 더미의 비교 횟수 + 누적합
    cout << acc + num1 + num2;
}
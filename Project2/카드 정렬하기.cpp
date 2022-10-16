#include <iostream>
#include <queue>
#include <vector>
using namespace std;

priority_queue<int, vector<int>, greater<int>> min_heap; // �ּ���
int acc = 0; // �������� �����ϴ� ����

int main()
{
    int n; // ī�� ������ ����
    cin >> n;
    if (n == 1) // ������ ������ 1����� ���� �ʿ䰡 �����Ƿ� 0�� �� �� ����
    {
        cout << acc;
        exit(0);
    }

    for (int i = 0; i < n; i++)
        // �� ī�� ���̰� �����ϴ� ī���� ������ �Է¹޾� �ּ����� ����
        // ī�� ������ ���� ������� ���� (�׸����� Ư��)
    {
        int num; cin >> num;
        min_heap.push(num);
    }

    while (min_heap.size() > 2)
        // ������ ���� ī�� ������ ���� 2�� ���� ���ٸ�
    {
        // ���� ���� ���� 2���� ��� �� Ƚ���� ���� ( num1 + num2 )
        int num1 = min_heap.top(); min_heap.pop(); 
        int num2 = min_heap.top(); min_heap.pop();

        min_heap.push(num1 + num2); // ī�� �� Ƚ���� �ٽ� �ּ����� ����
        acc += (num1 + num2); // �������� ����
    }

    // ���������� ���� �� ���� ī�� ���̸� ��
    int num1 = min_heap.top(); min_heap.pop();
    int num2 = min_heap.top();

    // ������ ������ ������ �� Ƚ�� + ������
    cout << acc + num1 + num2;
}
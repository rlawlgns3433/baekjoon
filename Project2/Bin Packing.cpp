#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int B;
vector<int> obj;

// �� ä��� �˰���
// �̺�Ž��
int Approx_BinPacking(int n, int c)
{
    int l = 0, r = n;
    // �̺�Ž������ �� ���� ������ ���̸� ���ϰ�, �̸� ���� ���̿� ��
    while (l <= --r)
    {
        // ���� ���̰� �� ��ٸ� ���� ������ �� ĭ ����������
        // ������ ������ �� ĭ �������� �̵�
        if (obj[l] + obj[r] <= c) l++;
        
        // �ʿ��� �� 1�� �߰�
        B++;
    }
    // �� �ʿ��� ���� �� ��ȯ
    return B; 
}

int main()
{
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int n, c;
    cin >> n >> c;
    obj.resize(n);
    // �뿡 �� ������ ���� �Է�
    for (int i = 0; i < n; i++)
    {
        cin >> obj[i];
    }
    // ������ ������������ ����
    sort(obj.begin(), obj.end());

    int answer = Approx_BinPacking(n, c);
    cout << answer;
}
#include <iostream>
#include <string>
#include <vector>
#define FOR(n,k) for(int i = 1; i <= n; i+=k)
#define endl '\n';
using namespace std;

/// <summary>
/// answer : ����
/// visited : ������ ��� ���θ� ������ �迭
/// v : ���� ������ ����� ���� �迭
/// </summary>

string answer = "";
bool visited[9] = { false };
vector<int> v;

void solution(int n, int m)
{
    if (m == 0) { // ������ ���̰� ���� �ȴٸ�
        // ���� ������ ����� ���ڹ迭�� ���信 ����
        for (auto e : v)
        {
            answer.append(to_string(e) + ' ');
        }
        answer.append("\n");
        return;
    };

    FOR(n, 1)
    {
        // ���� i�� ��� ���θ� �˻�
        if (visited[i] == false) // (������ �ʾ��� ��)
        {
            // ���� i�� ������� ó��
            visited[i] = true;
            // ���� ������ ����� �迭�� ���� i�� �߰�
            v.push_back(i);
            // ��������� ȣ�� 
            // ( 38�� line���� ���ڸ� 1�� �߰������Ƿ� m - 1)
            solution(n, m - 1);
            // ���� i�� ��� �� ó��
            v.pop_back();
            visited[i] = false;
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    // ���̰� 1�� ������ ���
    if (m == 1)
    {
        FOR(n, 1) cout << i << endl;
        return 0;
    }

    solution(n, m);

    cout << answer;
}
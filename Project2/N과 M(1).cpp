#include <iostream>
#include <string>
#include <vector>
#define FOR(n,k) for(int i = 1; i <= n; i+=k)
#define endl '\n';
using namespace std;

/// <summary>
/// answer : 정답
/// visited : 숫자의 사용 여부를 저장할 배열
/// v : 현재 수열에 사용한 숫자 배열
/// </summary>

string answer = "";
bool visited[9] = { false };
vector<int> v;

void solution(int n, int m)
{
    if (m == 0) { // 수열의 길이가 충족 된다면
        // 현재 수열에 사용한 숫자배열을 정답에 저장
        for (auto e : v)
        {
            answer.append(to_string(e) + ' ');
        }
        answer.append("\n");
        return;
    };

    FOR(n, 1)
    {
        // 숫자 i의 사용 여부를 검사
        if (visited[i] == false) // (사용되지 않았을 때)
        {
            // 숫자 i를 사용으로 처리
            visited[i] = true;
            // 현재 수열에 사용한 배열에 숫자 i를 추가
            v.push_back(i);
            // 재귀적으로 호출 
            // ( 38번 line에서 숫자를 1개 추가했으므로 m - 1)
            solution(n, m - 1);
            // 숫자 i를 사용 후 처리
            v.pop_back();
            visited[i] = false;
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    // 길이가 1인 수열을 출력
    if (m == 1)
    {
        FOR(n, 1) cout << i << endl;
        return 0;
    }

    solution(n, m);

    cout << answer;
}
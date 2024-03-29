#include <iostream> // input output stream : 입출력 함수들이 있는 헤더 파일
#define fastio (cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)) // 빠른 입출력을 위해 사용
using namespace std; // standard namespace : 기본적인 오브젝트들이 담겨있는 namespace

/// <summary>
/// A : 시작값
/// B : 최종값
/// cnt : A에서 B로 변하기 위해 필요한 연산 횟수
/// </summary>
int A, B, cnt = 1;

int main()
{
    fastio;
    cin >> A >> B;

    // A에서 B로 변환하는 연산이지만 그리디 알고리즘으로 풀기 위해 B에서 A로 변환하며 해결
    // 
    // 두 가지 연산을 하면서 실행이 가능
    // 
    // 1. A에 2를 곱하는 연산
    // 2. A의 끝 자리에 1을 더하는 연산
    //
    // 두 연산을 반대로 생각해보자
    // 
    // * B에서 A로 변환하기 위해서 필요한 연산 *
    // 1. B를 2로 나누는 연산 (B가 2의 배수일 때 처리)
    // 2. B에서 1을 빼고 그 값을 10으로 나누는 연산 (B의 일의 자릿수가 1일 때 처리)
    // [주의!] 2번 연산에서  B가 10으로 나누어 떨어져야 한다.
    // 즉, (B - 1)이 10의 배수여야만 한다.
    // 
    // 이외의 연산은 불가능하다. ex) 일의 자릿수가 남아있을 때 10으로 나누면 안 된다. 


    while (A < B) // 이 조건에서는 A와 B가 같아지거나 A가 B보다 커질 때 반복문을 종료한다.
    {
        if (B % 2 == 0) // 1번 연산 [B가 2의 배수일 때 처리]
        {
            B /= 2;
            cnt++;
        }
        else if (B % 10 == 1) // 2번 연산 [B의 일의 자릿수가 1일 때 처리]
        {
            B = (B - 1) / 10;
            cnt++;
        }
        else // 그 이외의 처리
        {
            cout << -1;
            return 0;
        }
    }
    if (A == B) cout << cnt; // 반복문을 탈출한 후 A와 B가 같다면(변환 완료), 연산 횟수를 출력
    else cout << -1; // B가 A보다 작아져서 탈출한 경우에(변환 불가), -1을 출력

    return 0; // 프로그램 종료
}
#include <iostream>
#include <vector>
using namespace std;

void gcd(vector<long long> v1)
{
    long long sum = 0;
    for (long long i = 0; i < v1.size(); i++)
    {
        for (long long j = i + 1; j < v1.size(); j++)
        {
            vector<long long> v = v1;
            long long r = 1;
            while (true)
            {
                r = v[i] % v[j];
                if (r == 0) break;
                else
                {
                    v[i] = v[j];
                    v[j] = r;
                }
            }
            sum += v[j];
        }
    }
    cout << sum << '\n';;
}

// 유클리드호제법
// 1. 두 수를 입력받는다.
/* 2. a를 b로 나눈 값 r을 저장한다.
*  3. r이 0이면 b를 출력한다. ( b = gcd) // 탈출 조건
*  4. r이 0이 아니면 a에 b를, b에는 r을 넣는다.
*  5. 2번으로 돌아가 실행한다.

*/

void process()
{
    long long n;
    cin >> n;
    vector<long long> v(n);

    for (long long i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    gcd(v);
}

int main()
{
    long long n;
    cin >> n;
    for (long long i = 0; i < n; i++)
    {
        process();
    }
}
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

// ��Ŭ����ȣ����
// 1. �� ���� �Է¹޴´�.
/* 2. a�� b�� ���� �� r�� �����Ѵ�.
*  3. r�� 0�̸� b�� ����Ѵ�. ( b = gcd) // Ż�� ����
*  4. r�� 0�� �ƴϸ� a�� b��, b���� r�� �ִ´�.
*  5. 2������ ���ư� �����Ѵ�.

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
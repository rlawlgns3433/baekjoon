#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
int n;

int find_gcd(int x, int y)
{
    if (x % y == 0) return y;
    else return find_gcd(y, x % y);
}

void process()
{
    for (int i = 1; i < n; i++)
    {
        int gcd = find_gcd(v[0], v[i]);
        cout << v[0] / gcd << '/' << v[i] / gcd << '\n';
    }
}

int main()
{
    cin >> n;
    v.resize(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    process();
}
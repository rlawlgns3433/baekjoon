#include <iostream>
#include <cmath>
using namespace std;

void process()
{
    int a, b;
    cin >> a >> b;
    int c = a;
    for (int i = 1; i < b; i++)
    {
        c = (c * a) % 10;
    }
    if (c % 10 == 0) cout << 10 << endl;
    else cout << c % 10 << endl;
}

int main()
{
    int caseSize;
    cin >> caseSize;
    for (int caseIndex = 1; caseIndex <= caseSize; caseIndex++)
    {
        process();
    }
}
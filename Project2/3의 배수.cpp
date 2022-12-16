#include <iostream>
#include <string>
using namespace std;

void process(string num, int& cnt, bool& isthree)
{
    int tmp = 0;
    if (num.length() <= 1)
    {
        if (stoi(num) % 3 == 0) isthree = true;
        return;
    }

    for (int i = 0; i < num.length(); i++)
    {
        tmp += num[i] - '0';
    }
    cnt++;
    process(to_string(tmp), cnt, isthree);
}

int main()
{
    string num;
    bool isthree = false;
    int cnt = 0;
    cin >> num;
    process(num, cnt, isthree);
    cout << cnt << endl;
    if (isthree)
        cout << "YES" << endl;
    else cout << "NO" << endl;
}
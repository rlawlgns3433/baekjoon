#include <iostream>
#include <string>
using namespace std;

int main()
{
    int cnt = 0;
    float sum = 0;
    string str;
    cin >> str;

    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == 'A')
        {
            sum += 4;
            cnt++;
        }
        else if (str[i] == 'B')
        {
            sum += 3;
            cnt++;
        }
        else if (str[i] == 'C')
        {
            sum += 2;
            cnt++;
        }
        else if (str[i] == 'D')
        {
            sum += 1;
            cnt++;
        }
        else if (str[i] == 'F')
        {
            cnt++;
        }

        if (str[i] == '+') sum += 0.5;
    }

    cout << sum / cnt;
}
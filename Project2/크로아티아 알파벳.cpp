#include <iostream>
using namespace std;

int main()
{
    string str;
    cin >> str;
    int count = 0;

    for (int i = 0; i < str.size(); ++i)
    {
        if (str[i] == 'c')
        {
            if (i + 1 < str.size() && (str[i + 1] == '=' || str[i + 1] == '-'))
            {
                i++;
                count++;
                continue;
            }
        }
        else if (str[i] == 'd')
        {
            if (i + 2 < str.size() && str[i + 1] == 'z' && str[i + 2] == '=')
            {
                i += 2;
                count++;
                continue;
            }
            else if (i + 1 < str.size() && str[i + 1] == '-')
            {
                i++;
                count++;
                continue;
            }
        }
        else if (i + 1 < str.size() && str[i] == 'l' && str[i + 1] == 'j')
        {
            i++;
            count++;
            continue;
        }
        else if (i + 1 < str.size() && str[i] == 'n' && str[i + 1] == 'j')
        {
            i++;
            count++;
            continue;
        }
        else if (i + 1 < str.size() && str[i] == 's' && str[i + 1] == '=')
        {
            i++;
            count++;
            continue;
        }
        else if (i + 1 < str.size() && str[i] == 'z' && str[i + 1] == '=')
        {
            i++;
            count++;
            continue;
        }

        count++;
    }

    cout << count;
}
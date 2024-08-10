#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str1, str2;
    getline(cin, str1);
    getline(cin, str2);

    int count = 0;
    int str1Len = str1.size();
    int str2Len = str2.size();

    for (int i = 0; i <= str1Len - str2Len; ++i)
    {
        if (str1.substr(i, str2Len) == str2)
        {
            ++count;
            i += str2Len - 1;
        }
    }

    cout << count;
}

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<string> stringVector;

    string input = "";
    int maxLen = 0;
    for (int i = 0; i < 5; ++i)
    {
        cin >> input;
        stringVector.push_back(input);
        maxLen = max(maxLen, (int)input.size());
    }

    for (int i = 0; i < maxLen; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            if (stringVector[j][i] == '\0')
                continue;
            cout << stringVector[j][i];
        }
    }
}
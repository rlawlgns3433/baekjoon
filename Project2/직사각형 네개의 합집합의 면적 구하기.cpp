#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<vector<bool>> v(101, vector<bool>(101, false));

    for (int i = 0; i < 4; ++i)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        for (int j = y1; j < y2; ++j)
        {
            for (int k = x1; k < x2; ++k)
            {
                v[j][k] = true;
            }
        }
    }

    int answer = 0;
    for (int i = 0; i < 101; ++i)
    {
        for (int j = 0; j < 101; ++j)
        {
            if (v[i][j])
            {
                answer++;
            }
        }
    }

    cout << answer;
}
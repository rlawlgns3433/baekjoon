#include <iostream>
using namespace std;

int Solution(int num)
{
    if (num < 10)
        num *= 10;

    int initNumber = num;

    int first = num / 10;
    int second = num % 10;

    int sum = second * 10 + (first + second) % 10;
    int count = 0;

    while (true)
    {
        if (sum == initNumber)
            return count;

        count++;

        first = sum / 10;
        second = sum % 10;
        sum = second * 10 + (first + second) % 10;
    }
}

int main()
{
    int num = 0;
    cin >> num;

    int answer = Solution(num);

    cout << answer + 1;
    return 0;
}
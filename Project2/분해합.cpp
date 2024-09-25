#include <iostream>
#include <string>

int DigitSum(int num)
{
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int Solution(int N)
{
    int start = std::max(1, N - 9 * (int)std::to_string(N).length());

    for (int i = start; i < N; ++i)
    {
        if (i + DigitSum(i) == N)
            return i;
    }
    return 0; 
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    int N;
    std::cin >> N;
    std::cout << Solution(N);
}

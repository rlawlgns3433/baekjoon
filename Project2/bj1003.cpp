#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int fib[41] = { 0 };

int fibonacci(int n) {
    if (n == 0) {
        fib[0] = 0;
    }
    else if (n == 1) {
        fib[1] = 1;
    }
    else if(fib[n] == 0){
        fib[n] = fibonacci(n-1) + fibonacci(n-2);
    }
    return fib[n];
}

int main()
{
    fibonacci(40);
    int n, fib_num;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &fib_num);
        if (fib_num == 0) printf("1 0\n");
        else printf("%d %d\n", fib[fib_num-1], fib[fib_num]);
    }
}
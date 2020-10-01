#include <stdio.h>

int Fibonacci(int);

int main()
{
    int n;

    while (scanf("%d", &n) != 1);

    printf("%d", Fibonacci(n));
}

int Fibonacci(int num)
{

    if (num > 1)
    {
        return Fibonacci(num - 1) + Fibonacci(num - 2);
    }
    else if (num == 1)
    {
        return 1;
    }
    else
        return 0;
}
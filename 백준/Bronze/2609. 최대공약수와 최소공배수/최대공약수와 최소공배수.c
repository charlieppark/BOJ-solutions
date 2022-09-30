#include <stdio.h>

int LCD(int a, int b);
int SCM(int lcd, int a, int b);

int main()
{
    int a, b, lcd, scm;

    scanf("%d %d", &a, &b);

    if (a != b)
    {
        lcd = LCD(a, b);

        scm = SCM(lcd, a, b);
    }
    else
    {
        lcd = a;
        scm = b;
    }

    printf("%d\n%d", lcd, scm);
}

int LCD(int a, int b)
{
    if (a % b == 0)
        return b;

    if (b % a == 0)
        return a;

    int temp_a = a;
    int temp_b = b;
    int smaller = a < b ? a : b;
    int lcd = 1;

    for (int i = 2; i < smaller; i++)
    {
        if (!(temp_a % i) && !(temp_b % i))
        {
            temp_a /= i;
            temp_b /= i;
            smaller /= i;
            lcd *= i;
            i--;
        }
    }

    return lcd;
}

int SCM(int lcd, int a, int b)
{
    if (a % b == 0)
        return a;

    if (b % a == 0)
        return b;

    int scm = 1;

    scm *= lcd;
    scm *= (a / lcd);
    scm *= (b / lcd);

    return scm;
}
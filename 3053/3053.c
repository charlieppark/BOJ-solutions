#include <stdio.h>

#define PI 3.14159265358979

int main()
{
    int R;
    while (scanf("%d", &R) != 1) continue;

    double arith_area, taxi_area;
    arith_area = (double)(R * R) * PI;
    taxi_area = (double)(R * R) * 2;

    printf("%lf\n%lf", arith_area, taxi_area);
}
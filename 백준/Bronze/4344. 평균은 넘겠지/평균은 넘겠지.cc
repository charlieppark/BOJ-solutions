#include <stdio.h>
#include <stdlib.h>

void calc();

int main()
{
    int C;
    scanf("%d", &C);
    for(int k = 0; k<C; k++)
    {
        calc();
    }
    return 0;
}

void calc()
{
    int N;
    double mean = 0.0;
    int count = 0;
    int* num;
    scanf("%d", &N);
    num = (int*)malloc(sizeof(int)*N);
    for (int i = 0; i<N; i++)
    {
        scanf("%d", &num[i]);
        mean += (double)num[i];
    }
    mean = mean/(double)N;
    for (int t = 0; t<N; t++)
    {
        if(mean < num[t])
            count++;
    }
    printf("%2.3f%%\n", 100.000*(double)count/(double)N);
    return;
}
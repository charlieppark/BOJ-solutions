#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int num;
    char* OnX = (char*)malloc(sizeof(char) * 80);
    int temp_score;
    int score;

    while(scanf("%d", &num) != 1) continue;

    for (int i = 0; i < num; i++)
    {
        temp_score = 0;
        score = 0;

        while(scanf("%s", OnX) != 1) continue;
        for (int k = 0; k < strlen(OnX); k++)
        {
            if (OnX[k] == 'O')
                temp_score++;
            else
                temp_score = 0;
            score += temp_score;
        }
        printf("%d\n", score);
    }
}
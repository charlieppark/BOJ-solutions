#include <stdio.h>

int main()
{
    int melon;
    scanf("%d", &melon);
    
    int path[6];
    int len[6];
    
    for (int i = 0; i < 6; i++) {
        scanf("%d %d", path+i, len+i);
    }
    
    int erase_area;
    int erase_index;
    int side_1, side_2;
    
    for (int i = 0; i < 6; i++) {
        int a, b, c, d, e, f;
        a = i;
        b = (i + 1) % 6;
        c = (i + 2) % 6;
        d = (i + 3) % 6;
        side_1 = (i + 4) % 6;
        side_2 = (i + 5) % 6;
        
        if (path[a] == 3 && path[b] == 1 && path[c] == 3 && path[d] == 1) {
            erase_area = len[b] * len[c];
            break;
        }
        if (path[a] == 4 && path[b] == 2 && path[c] == 4 && path[d] == 2) {
            erase_area = len[b] * len[c];
            break;
        }
        if (path[a] == 2 && path[b] == 3 && path[c] == 2 && path[d] == 3) {
            erase_area = len[b] * len[c];
            break;
        }
        if (path[a] == 1 && path[b] == 4 && path[c] == 1 && path[d] == 4) {
            erase_area = len[b] * len[c];
            break;
        }
    }
    
    printf("%d", melon * (len[side_1]*len[side_2] - erase_area));
}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#define max(a, b) ((a) > (b) ? (a) : (b))

int X[1000];
int n, k, m, check = 0, cnt = 0;
char res[100][100];

void inkq()
{
    check = 1;
    for (int i = 1; i <= n; i++)
    {
        if (X[i] == 1)
            res[cnt][i] = 'x';
        else
            res[cnt][i] = '_';
    }
    cnt++;
}

void backtrack(int i, int one, int zero)
{
    for (int j = 0; j <= 1; j++)
    {
        X[i] = j;
        if (j == 0 && zero > m - 1)
            continue;
        if (i == n)
        {
            if (one + (j == 1) >= k)
                inkq();
        }
        else
        {
            if (j == 0 && zero < m - 1)
                backtrack(i + 1, one, zero + 1);
            if (j == 1)
                backtrack(i + 1, one + 1, zero);
        }
    }
}

int main()
{
    scanf("%d%d%d", &n, &m, &k);
    backtrack(1, 0, 0);
    if (!check)
        printf("-1");
    else
    {
        printf("%d\n", cnt);
        for (int i = 0; i < cnt; i++)
        {
            for (int j = 1; j <= n; j++)
                printf("%c", res[i][j]);
            printf("\n");
        }
    }
    return 0;
}
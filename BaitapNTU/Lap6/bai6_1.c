#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#define max(a, b) ((a) > (b) ? (a) : (b))

int X[1000], n, k, m, check = 0;
void inkq()
{
    check = 1;
    for (int i = 1; i <= n; i++)
    {
        printf("%d", X[i]);
    }
    printf("\n");
}

void backtrack(int one, int zero, int i)
{
    for (int j = 0; j <= 1; j++)
    {
        X[i] = j;
        if (j == 1 && one > k)
            continue;
        if (j == 0 && zero > m - 1)
            continue;
        if (i == n)
        {
            if (one + (j == 1) == k)
                inkq();
        }
        else
        {
            if (one < k && j == 1)
            {
                backtrack(one + 1, 0, i + 1);
            }
            if (zero < m - 1 && j == 0)
            {
                backtrack(one, zero + 1, i + 1);
            }
        }
    }
}

int main()
{
    printf("nhap n, k, m: ");
    scanf("%d%d%d", &n, &k, &m);
    backtrack(0, 0, 1);
    if (!check)
        printf("khong co cach in");
    return 0;
}
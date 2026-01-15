#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#define max(a, b) ((a) > (b) ? (a) : (b))

int X[1000], a[1000];
int n, s, check = 0;

void inkq(int i)
{
    check = 1;
    for (int j = 1; j <= i; j++)
    {
        printf("%d ", X[j]);
        if (j != i)
            printf("+ ");
    }
    printf("\n");
}

void backtrack(int i, int start, int sum)
{
    for (int j = start; j <= n; j++)
    {
        X[i] = a[j];
        if (sum + X[i] > s)
            break;
        sum += X[i];
        if (sum == s)
        {
            inkq(i);
        }
        else
        {
            backtrack(i + 1, j + 1, sum);
        }
        sum -= X[i];
    }
}

int main()
{
    printf("nhap n, s: ");
    scanf("%d%d", &n, &s);
    for (int i = 1; i <= n; i++)
    {
        printf("a[%d]: ", i - 1);
        scanf("%d", &a[i]);
    }
    backtrack(1, 1, 0);
    if (!check)
        printf("khong co cach in");
    return 0;
}
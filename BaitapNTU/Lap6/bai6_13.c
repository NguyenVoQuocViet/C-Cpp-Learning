#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#define max(a, b) ((a) > (b) ? (a) : (b))
#define MAX 100

void init(int n, int a[], int dp[])
{
    for (int i = 1; i <= n; i++)
    {
        printf("nhap a[%d]: ", i);
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++)
        dp[i] = 1;
    dp[0] = 0;
}

void LIS(int n, int a[], int dp[], int truyvet[])
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            if (a[j] < a[i])
            {
                if (dp[i] < dp[j] + 1)
                {
                    dp[i] = dp[j] + 1;
                    truyvet[i] = j;
                }
            }
        }
    }
}

void xuat(int n, int a[], int dp[], int truyvet[])
{
    int res = INT_MIN, idx = 0;
    for (int i = 1; i <= n; i++)
    {
        if (res < dp[i])
        {
            res = dp[i];
            idx = i;
        }
    }
    printf("Do dai: %d\n", res);
    
    int ans[MAX], cnt = 0;
    while (idx != 0)
    {
        ans[cnt++] = a[idx];
        idx = truyvet[idx];
    }
    printf("Day con: ");
    for (int i = cnt - 1; i >= 0; i--)
        printf("%d ", ans[i]);
}

int main()
{
    int n, a[MAX], dp[MAX], truyvet[MAX] = {0};
    printf("nhap n: ");
    scanf("%d", &n);
    init(n, a, dp);
    LIS(n, a, dp, truyvet);
    xuat(n, a, dp, truyvet);
    return 0;
}
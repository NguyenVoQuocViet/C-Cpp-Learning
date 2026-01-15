#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#define max(a, b) ((a) > (b) ? (a) : (b))
#define MAX 100

void init(int n, int s, int a[], int dp[][MAX])
{
    for (int i = 1; i <= n; i++)
    {
        printf("a[%d]: ", i);
        scanf("%d", &a[i]);
    }
    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;
    for (int j = 1; j <= s; j++)
        dp[0][j] = 0;
}

void sumS(int n, int s, int a[], int dp[][MAX])
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= s; j++)
        {
            if (j >= a[i])
            {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - a[i]];
            }
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
}

void xuat(int n, int s, int a[], int dp[][MAX])
{
    if (!dp[n][s])
        printf("Khong co day con co tong bang s");
    else
    {
        int i = n, j = s;
        int res[MAX], cnt = 0;
        while (i > 0 && j > 0)
        {
            if (dp[i][j] != dp[i - 1][j])
            {
                res[cnt++] = a[i];
                j -= a[i];
            }
            i--;
        }
        for (int i = 0; i < cnt; i++)
            printf("%d ", res[i]);
    }
}

int main()
{
    int n, s;
    printf("nhap n: ");
    scanf("%d", &n);
    printf("nhap s: ");
    scanf("%d", &s);
    int a[MAX], dp[MAX][MAX];
    init(n, s, a, dp);
    sumS(n, s, a, dp);
    xuat(n, s, a, dp);
    return 0;
}
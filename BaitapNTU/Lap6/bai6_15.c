#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#define max(a, b) ((a) > (b) ? (a) : (b))
#define MAX 50

void readFile(int* n, int* m, int v[], int w[])
{
    FILE* fin = fopen("knapsack.txt", "r");
    if (fin != NULL)
    {
        fscanf(fin, "%d%d", n, m);

        for (int i = 1; i <= (*n); i++)
            fscanf(fin, "%d", &v[i]);
        for (int i = 1; i <= (*n); i++)
            fscanf(fin, "%d", &w[i]);
        fclose(fin);
    }
    else
        printf("Err");
}

void knapsack(int n, int m, int v[], int w[], int dp[][MAX])
{
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;
    for (int i = 1; i <= m; i++)
        dp[0][i] = 0;
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (j >= w[i])
            {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
            }
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
}

void xuat(int n, int m, int v[], int w[], int dp[][MAX])
{
    printf("Tong gia tri lon nhat: %d\n", dp[n][m]);
    int i = n, j = m;
    printf("Cac vat duoc chon: \n");
    while (i > 0 && j > 0)
    {
        if (j >= w[i] && dp[i - 1][j - w[i]] + v[i] == dp[i][j])
        {
            printf("w: %d v: %d\n", w[i], v[i]);
            j -= w[i];
        }
        i--;
    }
}

int main()
{
    int n, m, v[MAX], w[MAX];
    readFile(&n, &m, v, w);
    int dp[MAX][MAX];
    knapsack(n, m, v, w, dp);
    xuat(n, m, v, w, dp);
    return 0;
}
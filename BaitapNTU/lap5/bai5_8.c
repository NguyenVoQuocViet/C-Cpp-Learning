#include <stdio.h>
#include <stdlib.h>
#define MAX 35
#define max(a, b) ((a) > (b) ? (a) : (b))

void readFile(int* n, int* m, int v[], int w[])
{
    FILE* fin = fopen("Knapsack.txt", "r");
    if (fin != NULL)
    {
        fscanf(fin, "%d%d", n, m);
        if (*n >= 30)
        {
            printf("n khong hop le!");
            return;
        }
        for (int i = 1; i <= *n; i++)
            fscanf(fin, "%d", &v[i]);
        for (int i = 1; i <= *n; i++)
            fscanf(fin, "%d", &w[i]);
        fclose(fin);
    }
    else
        printf("NOT OPEN FILE!");
}

void truyvet(int n, int m, int dp[][m + 1], int v[], int w[])
{
    FILE* fout = fopen("knapsack_out.txt", "w");
    int i = n, j = m;
    while (i > 0 && j > 0)
    {
        if (dp[i][j] == dp[i - 1][j])
        {
            i--;
        }
        else
        {
            fprintf(fout, "Vat thu: %d, gia tri: %d, trong luong: %d\n", i, v[i], w[i]);
            j -= w[i];
            i--;
        }
    }
    fclose(fout);
}

int knapsack_qhd(int n, int m, int v[], int w[], int dp[][m + 1])
{
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = 0;
        for (int j = 1; j <= m; j++)
        {
            dp[0][j] = 0;
            if (j >= w[i])
            {
                dp[i][j] = max(dp[i - 1][j - w[i]] + v[i], dp[i - 1][j]);
            }
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][m];
}

int main()
{
    int n, m;
    int v[MAX], w[MAX];
    readFile(&n, &m, v, w);
    int dp[n + 1][m + 1];
    int res = knapsack_qhd(n, m, v, w, dp);
    truyvet(n, m, dp, v, w);
    return 0;
}
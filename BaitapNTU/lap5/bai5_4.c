#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 35
#define min(a, b) (a) < (b) ? (a) : (b)

void readFile(int a[], int* n, int* s);
void atm_gioi_han(int a[], int n, int s);
void atm2_gioi_han(int a[], int n, int s);
void atm3_vo_han(int a[], int n, int s);


int main()
{
    int n, s;
    int a[MAX];

    readFile(a, &n, &s);
    atm_gioi_han(a, n, s);
    printf("\n");
    atm2_gioi_han(a, n, s);
    printf("\n");
    atm3_vo_han(a, n, s);
    return 0;
}

void readFile(int a[], int* n, int* s)
{
    FILE* fin = fopen("ATM.txt", "r");
    if (fin != NULL)
    {
        fscanf(fin, "%d%d", n, s);
        if (*n >= 30)
        {
            printf("n khong hop le!");
            return;
        }
        for (int i = 1; i <= *n; i++)
        {
            fscanf(fin, "%d", &a[i]);
        }
    }
    else
        printf("NOT OPEN FILE");
}

// atm moi to tien chon 1 lan
void atm_gioi_han(int a[], int n, int s)
{
    int truyvet[s + 1];
    for (int i = 0; i <= s; i++)
        truyvet[i] = -1;
    int dp[s + 1];
    dp[0] = 0;
    for (int i = 1; i <= s; i++)
        dp[i] = INT_MAX;

    for (int i = 1; i <= n; i++)
    {
        for (int j = s; j >= 1; j--)
        {
            if (j - a[i] >= 0 && dp[j - a[i]] != INT_MAX)
            {
                if (dp[j - a[i]] + 1 < dp[j])
                {
                    dp[j] = dp[j - a[i]] + 1;
                    truyvet[j] = a[i];
                }
            }
        }
    }
    if (dp[s] != INT_MAX)
    {
        printf("%d\n", dp[s]);
        int x = s;
        while (x > 0)
        {
            printf("%d ", truyvet[x]);
            x -= truyvet[x];
        }
    }
    else
        printf("Khong doi duoc\n");
}

void atm2_gioi_han(int a[], int n, int s)
{
    int dp[n + 1][s + 1];
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= s; j++)
            dp[i][j] = INT_MAX;
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = 0;
        for (int j = 1; j <= s; j++)
        {
            if (j >= a[i] && dp[i - 1][j - a[i]] != INT_MAX)
            {
                dp[i][j] = min(dp[i - 1][j - a[i]] + 1, dp[i - 1][j]);
            }
            else    
                dp[i][j] = dp[i - 1][j];
        }
    }
    if (dp[n][s] != INT_MAX)
    {
        printf("%d\n", dp[n][s]);
        int i = n, j = s;
        while (i > 0 && j > 0)
        {
            if (dp[i][j] != dp[i - 1][j])
            {
                printf("%d ", a[i]);
                j -= a[i];
            }
            else
                i--;
        }
    }
    else
        printf("Khong doi duoc");
}

// atm vo han tien
void atm3_vo_han(int a[], int n, int s)
{
    int dp[n + 1][s + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= s; j++)
            dp[i][j] = INT_MAX;
    }
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = 0;
        for (int j = 1; j <= s; j++)
        {
            if (j >= a[i] && dp[i][j - a[i]] != INT_MAX)
                dp[i][j] = min(dp[i][j - a[i]] + 1, dp[i-1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    if (dp[n][s] != INT_MAX)
    {
        printf("%d\n", dp[n][s]);
        int i = n, j = s;
        while (i > 0 && j > 0)
        {
            if (dp[i - 1][j] == dp[i][j])
            {
                i--;
            }
            else
            {
                printf("%d ", a[i]);
                j -= a[i];
            }
        }
    }
    else
        printf("Khong chon duoc\n");
}

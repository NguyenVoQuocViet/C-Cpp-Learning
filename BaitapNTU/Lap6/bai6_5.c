#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#define max(a, b) ((a) > (b) ? (a) : (b))

int cnt = 0, X[100], res[100][100];

void inkq(int w[], int i)
{
    for (int j = 0; j <= i; j++)
    {
        res[cnt][j] = X[j];
    }
    cnt++;
}

void backtrack(int w[], int i, int m, int sum, int n)
{
    if (sum > m || i >= n)
        return;
    for (int j = 0; j <= 1; j++)
    {
        X[i] = j;
        int s = sum + (j == 1 ? w[i] : 0);

        if (s == m)
        {
            inkq(w, i);
        }
        else if (s < m)
            backtrack(w, i + 1, m, s, n);
    }
}

void backtrack1(int w[], int i, int m, int sum, int n)
{
    if (sum > m || i >= n)
        return;
    if (sum == m)
    {
        inkq(w, i - 1);
        return;
    }

    X[i] = 0;
    backtrack1(w, i + 1, m, sum, n);
    X[i] = 1;
    backtrack1(w, i + 1, m, sum + w[i], n);
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    int w[25];
    for (int i = 0; i < n; i++)
        scanf("%d", &w[i]);
    backtrack1(w, 0, m, 0, n);
    if (cnt == 0)
        printf("Khong chon duoc");
    else
    {
        printf("%d\n", cnt);
        for (int i = 0; i < cnt; i++)
        {
            for (int j = 0; j < n; j++)
                if (res[i][j])
                    printf("%d ", w[j]);
            printf("\n");
        }
    }
    return 0;
}
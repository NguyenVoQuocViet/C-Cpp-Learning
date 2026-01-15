#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#define max(a, b) ((a) > (b) ? (a) : (b))
#define MAX 25

char X[MAX], res[100][100];
int cnt = 0;

void inkq(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
        res[cnt][i] = X[i];
    cnt++;
}

void backtrack(int a[], int i, int n, int sum)
{
    if (i == n - 1)
    {
        if (sum == 0)
            inkq(a, n);
        return;
    }

    X[i] = '-';
    backtrack(a, i + 1, n, sum - a[i+1]);
    X[i] = '+';
    backtrack(a, i + 1, n, sum + a[i+1]);
}

int main()
{
    int n, a[MAX];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    backtrack(a, 0, n, a[0]);
    if (cnt == 0)
        printf("0");
    else
    {
        printf("%d\n", cnt);   
        for (int i = 0; i < cnt; i++)
        {
            for (int j = 0; j < n; j++)
            {
                printf("%d", a[j]);
                if (j < n - 1)
                    printf(" %c ", res[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
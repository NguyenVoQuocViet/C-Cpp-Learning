#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#define max(a, b) ((a) > (b) ? (a) : (b))
#define MAX 55

char X[MAX], res[100][100];
int cnt = 0;

void inkq(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        res[cnt][i] = X[i];
    }
    cnt++;
}

void backtrack(int a[], int i, int n, int need, int sumA, int sumB)
{
    if (sumA > need || sumB > need)
        return;
    if (i == n)
    {
        if (sumA == need)
        {
            inkq(a, n);
        }
        return;
    }
    X[i] = 'A';
    backtrack(a, i + 1, n, need, sumA + a[i], sumB);
    X[i] = 'B';
    backtrack(a, i + 1, n, need, sumA, sumB + a[i]);
}

int main()
{
    int n, a[MAX], sum = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        sum += a[i];
    }

    if (sum % 2 != 0)
    {
        printf("Khong chia duoc");
        return 0;
    }
    int need = sum / 2;
    backtrack(a, 0, n, need, 0, 0);
    printf("%d\n", cnt);
    for (int i = 0; i < cnt; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%c ", res[i][j]);
        printf("\n");
    }
    return 0;
}
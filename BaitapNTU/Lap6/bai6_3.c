#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#define max(a, b) ((a) > (b) ? (a) : (b))

int n, a[1000], X[1000], used[1000], check = 0;

void inkq(int i)
{
    check = 1;
    for (int j = 1; j <= i; j++)
    {
        printf("%d ", X[j]);
    }
    printf("| ");
    for (int j = 1; j <= n; j++)
    {
        if (!used[j])
            printf("%d ", a[j]);
    }
    printf("\n");
}

void backtrack(int i, int sum, int curr_sum, int start)
{
    for (int j = start; j <= n; j++)
    {
        X[i] = a[j];
        if (curr_sum + a[j] > sum - (curr_sum + a[j]))
            continue;
        curr_sum += X[i];
        used[j] = 1;
        if (curr_sum == sum - curr_sum)
        {
            inkq(i);
        }
        else
            backtrack(i + 1, sum, curr_sum, j + 1);
        curr_sum -= a[j];
        used[j] = 0;
    }
}

int main()
{
    printf("nhap n: ");
    scanf("%d", &n);
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        printf("a[%d]: ", i - 1);
        scanf("%d", &a[i]);
        sum += a[i];
    }
    if (sum % 2 != 0)
    {
        printf("khong chia duoc tap con");
        return 0;
    }
    else
        backtrack(1, sum, 0, 1);
    if (!check)
        printf("khong chia duoc tap con");
    return 0;
}
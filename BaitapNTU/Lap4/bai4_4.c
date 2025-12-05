#include <stdio.h>
#include <stdlib.h>

int X[100];
// cau a
void inkq(int k)
{
    printf("(");
    for (int i = 1; i <= k; i++)
    {
        printf("%d", X[i]);
        if (i != k)
            printf(",");
    }
    printf(") ");
}
// cach 1
void backtrack_a(int n, int k, int i, int start)
{
    for (int j = start; j <= n - k + i; j++)
    {
        X[i] = j;
        if (i == k)
        {
            inkq(k);
        }
        else
            backtrack_a(n, k, i + 1, j + 1);
    }
}
// cach 2
void backtrack_a2(int n, int k, int i)
{
    for (int j = X[i - 1] + 1; j <= n - k + i; j++)
    {
        X[i] = j;
        if (i == k)
        {
            inkq(k);
        }
        else
            backtrack_a2(n, k, i + 1);
    }
}
// cau b
int used[100];
void backtrack_b(int n, int k, int i)
{
    for (int j = 1; j <= n; j++)
    {
        if (!used[j])
        {
            used[j] = 1;
            X[i] = j;
            if (i == k)
            {
                inkq(k);
            }
            else
                backtrack_b(n, k, i + 1);
            used[j] = 0;
        }
    }
}
int main()
{
    int k, n;
    printf("nhap k va n: ");
    scanf("%d%d", &k, &n);
    //backtrack_a(n, k, 1, 1); printf("\n");
    backtrack_a2(n, k, 1); printf("\n");
    backtrack_b(n, k, 1);
    return 0;
}
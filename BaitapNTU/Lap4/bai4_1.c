#include <stdio.h>
#include <stdlib.h>

int X[20];

void in(int n)
{
    for (int i = 1; i <= n; i++)
        printf("%d", X[i]);
    printf("\n");
}
// cach 1
void backtrack1(int i, int n)
{
    for (int j = 0; j <= 1; j++)
    {
        X[i] = j;
        if (i == n)
        {
            in(n);
        }
        else
            backtrack1(i + 1, n);
    }
}
//cach 2
void backtrack2(int i, int n)
{
    if (i == n)
    {
        in(n);
        return;
    }
    X[i] = 0;
    backtrack2(i + 1, n);
    X[i] = 1;
    backtrack2(i + 1, n);
}

int main()
{
    int n;
    do
    {
        printf("nhap 0 < n <= 10: ");
        scanf("%d", &n);
    }while (n <=0 || n > 10);
    backtrack1(1, n);
    // backtrack2(1, n);
    return 0;
}
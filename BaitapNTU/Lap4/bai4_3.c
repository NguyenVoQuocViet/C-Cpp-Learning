#include <stdio.h>
#include <stdlib.h>

int X[100];
int s[100];
FILE* fout;
int check = 0;
// cach 1
void in(int n)
{
    check = 1;
    for (int i = 0; i < n; i++)
    {
        fprintf(fout, "%d", X[i]);
        if (i != n - 1)
            fprintf(fout, " + ");
    }
    fprintf(fout, "\n");
}

void backtrack(int i, int start, int n, int sum)
{
    for (int j = start; j <= n; j++)
    {
        X[i] = j;
        sum += j;
        if (sum > n)
        {
            sum -= j;
            break;
        }
        if (sum == n)
        {
            in(i + 1);
        }
        else    
            backtrack(i + 1, j, n, sum);
        sum -= j;
    }
}
// cach 2
void in2(int n)
{
    check = 1;
    for (int i = 1; i < n; i++)
    {
        fprintf(fout, "%d", X[i]);
        if (i != n - 1)
            fprintf(fout, " + ");
    }
    fprintf(fout, "\n");
}

void backtrack2(int i, int n)
{
    for (int j = X[i - 1]; j <= (n - s[i - 1]); j++)
    {
        X[i] = j;
        s[i] = s[i - 1] + j;
        if (s[i] == n)
        {
            in2(i + 1);
        }
        else
            backtrack2(i + 1, n);
    }
}

int main()
{
    fout = fopen("Lab4_3.out", "w");
    int n;
    do
    {
        printf("nhap n: ");
        scanf("%d", &n);
    } while (n <= 0 || n >= 20);
    
    // backtrack(0, 1, n, 0);
    X[0] = 1;
    s[0] = 0;
    backtrack2(1, n);
    if (!check)
        fprintf(fout, "%d", -1);
    fclose(fout);
    return 0;
}
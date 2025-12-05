#include <stdio.h>
#include <stdlib.h>
#define MAX 50

FILE* fout;
int X[100], best, used[100], mintp = INT_MAX, check = 0;

void readFile(int a[][MAX], int *n)
{
    FILE *fin = fopen("Dulich.inp", "r");
    if (fin != NULL)
    {
        fscanf(fin, "%d", n);
        if (*n <= 1 || *n >= 30)
        {
            printf("n khong hop le!");
            return;
        }

        for (int i = 0; i < *n; i++)
            for (int j = 0; j < *n; j++)
            {
                fscanf(fin, "%d", &a[i][j]);
                if (a[i][j] != 0)
                    mintp = mintp > a[i][j] ? a[i][j] : mintp;
            }
        
        fclose(fin);
    }
    else
        printf("NOT OPEN FILE!");
}

void inkq(int a[][MAX], int n)
{
    fseek(fout, 0, SEEK_SET);
    if (fout != NULL)
    {
        check = 1;
        for (int i = 0; i < n; i++)
        {
            fprintf(fout, "TP%d -> ", X[i] + 1);
        }
        fprintf(fout, "TP1\n");
        fprintf(fout, "Tong chi phi la: %d", best);
    }
    else
        printf("NOT OPEN FILE!");
}

void backtrack(int a[][MAX], int n, int i, int curr)
{
    for (int j = 1; j < n; j++)
    {
        if (!used[j])
        {
            used[j] = 1;
            X[i] = j;
            curr += a[X[i - 1]][X[i]];
            if (i == n - 1)
            {   
                int tmp = curr + a[X[i]][X[0]];
                if (tmp < best)
                {
                    best = tmp;
                    inkq(a, n);
                }
            }
            else if (curr + (n - i) * mintp < best)
                backtrack(a, n, i + 1, curr);
            curr -= a[X[i - 1]][X[i]];
            used[j] = 0;
        }
    }
}

int main()
{
    int a[MAX][MAX];
    int n;
    readFile(a, &n);
    fout = fopen("Dulich.out", "w");
    best = INT_MAX;
    X[0] = 0;
    used[0] = 1;
    backtrack(a, n, 1, 0);
    if (!check)
        fprintf(fout, "-1");
    fclose(fout);
    return 0;
}
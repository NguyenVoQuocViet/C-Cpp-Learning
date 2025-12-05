#include <stdio.h>
#include <stdlib.h>
#define MAX 50

int X[100], sum;
FILE *fout;
int check = 0;

void docFile(int a[], int *n, int *s)
{
    FILE *fin = fopen("ATM.inp", "r");
    if (fin != NULL)
    {
        fscanf(fin, "%d", n);
        fscanf(fin, "%d", s);
        for (int i = 0; i < *n; i++)
            fscanf(fin, "%d", &a[i]);
        fclose(fin);
    }
    else
        printf("NOT OPEN FILE");
}
// cach 1
void in1(int n)
{
    if (fout != NULL)
    {
        for (int i = 0; i < n; i++)
        {
            fprintf(fout, "%d ", X[i]);
        }
        fprintf(fout, "\n");
    }
    else
        printf("NOT OPEN FILE!");
}

void backtrack1(int a[], int i, int start, int n, int s)
{
    for (int j = start; j < n; j++)
    {
        X[i] = a[j];
        sum += a[j];
        if (sum > s)
        {
            sum -= a[j];
            continue;
        }
        if (sum == s)
        {
            in1(i + 1);
            check = 1;
        }
        else
            backtrack1(a, i + 1, j + 1, n, s);
        sum -= a[j];
    }
}

// cach 2

void in2(int a[], int n, int s)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (X[i])
            sum += a[i];
    }
    if (sum == s)
    {
        check = 1;
        for (int i = 0; i < n; i++)
        {
            if (X[i])
                fprintf(fout, "%d ", a[i]);
        }
        fprintf(fout, "\n");
    }
}

void backtrack2(int a[], int i, int n, int s, int sum)
{
    for (int j = 0; j <= 1; j++)
    {
        X[i] = j;
        int tong = sum + a[i] * j;
        if (tong > s)
            continue;
        if (i == n - 1)
        {
            in2(a, n, s);
        }
        else
            backtrack2(a, i + 1, n, s, tong);
    }
}

// cach 3

void backtrack3(int a[], int i, int n, int s, int sum)
{
    if (sum > s)
        return;
    if (i == n)
    {
        in2(a, n, s);
        return;
    }
    
    X[i] = 0;
    backtrack3(a, i + 1, n, s, sum);
    X[i] = 1;
    backtrack3(a, i + 1, n, s, sum + a[i]);
}

int main()
{
    fout = fopen("ATM_out.out", "w");
    int n, s;
    int a[MAX];
    docFile(a, &n, &s);

    backtrack1(a, 0, 0, n, s);
    // backtrack2(a, 0, n, s);
    // backtrack3(a, 0, n, s);
    if (!check)
    {
        fprintf(fout, "%d", -1);
    }

    fclose(fout);
    return 0;
}
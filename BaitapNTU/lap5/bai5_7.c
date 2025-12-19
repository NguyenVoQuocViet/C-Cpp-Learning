#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define MAX 35

void readFile(int* n, int a[][MAX]);
void writeFile(int res[], int min_cost, int n);
int nguoiDuLichGreedy(int a[][MAX], int n, int res[]);

int main()
{
    int n;
    int a[MAX][MAX];
    readFile(&n, a);
    int res[n + 1], min_cost;
    min_cost = nguoiDuLichGreedy(a, n, res);
    if (min_cost == -1)
    {
        FILE* fout = fopen("dulich_out.txt", "w");
        fprintf(fout, "-1");
        fclose(fout);
    }
    else
        writeFile(res, min_cost, n);
    return 0;
}

void readFile(int* n, int a[][MAX])
{
    FILE* fin = fopen("dulich.txt", "r");
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
                fscanf(fin, "%d", &a[i][j]);
        fclose(fin);
    }
    else
    {
        printf("NOT OPEN FILE!");
    }
}

void writeFile(int res[], int min_cost, int n)
{
    FILE* fout = fopen("dulich_out.txt", "w");
    for (int i = 0; i <= n; i++)
    {
        fprintf(fout, "TP%d", res[i] + 1);
        if (i != n)
        {
            fprintf(fout, " -> ");
        }
    }
    fprintf(fout, "\nTong chi phi la: %d", min_cost);
    fclose(fout);
}

int nguoiDuLichGreedy(int a[][MAX], int n, int res[])
{
    int visited[n], prev_city = 0, cnt = 0, min_cost = 0;
    res[cnt++] = 0;
    for (int i = 0; i < n; i++)
        visited[i] = 0;
    visited[prev_city] = 1;
    while (cnt < n)
    {
        int curr_city = -1, curr_min_cost = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            if (visited[i] != 1 && a[prev_city][i] > 0)
            {
                if (curr_min_cost > a[prev_city][i])
                {
                    curr_min_cost = a[prev_city][i];
                    curr_city = i;
                }
            }
        }
        if (curr_city == -1)
            return -1;
        min_cost += curr_min_cost;
        res[cnt++] = curr_city;
        prev_city = curr_city;
        visited[prev_city] = 1;
    }

    if (a[prev_city][0] <= 0)
        return -1;

    min_cost += a[prev_city][0];
    res[cnt++] = 0;
    return min_cost;
}
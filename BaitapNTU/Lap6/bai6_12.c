#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#define min(a, b) ((a) > (b) ? (b) : (a))
#define MAX 100

void init(int n, int c[][MAX])
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            printf("nhap c[%d][%d]=c[%d][%d]: ", i, j, j, i);
            scanf("%d", &c[i][j]);
            c[j][i] = c[i][j];
        }
        c[i][i] = 0;
    }
}

int greedy(int n, int c[][MAX], int X[])
{
    int prev = 1, min_cost = 0, i = 2, visited[MAX] = {0};
    X[1] = 1;
    visited[1] = 1;

    while (i <= n)
    {
        int cost = INT_MAX, city = -1;
        for (int j = 1; j <= n; j++)
        {
            if (c[prev][j] > 0 && visited[j] == 0)
            {
                if (c[prev][j] < cost)
                {
                    cost = c[prev][j];
                    city = j;
                }
            }
        }
        if (city != -1)
        {
            X[i] = city;
            min_cost += cost;
            prev = city;
            visited[prev] = 1;
            i++;
        }
        else
            break;
    }

    X[i] = 1;
    min_cost += c[prev][1];
    return min_cost;
}

void xuat(int n, int c[][MAX], int X[], int cost)
{
    printf("Chi phi nho nhat: %d\n", cost);
    for (int i = 1; i <= n + 1; i++)
    {
        printf("%d", X[i]);
        if (i != n + 1)
            printf(" -> ");
    }
}

int main()
{
    int n, c[MAX][MAX], X[MAX];
    printf("nhap n: ");
    scanf("%d", &n);
    init(n, c);
    int cost = greedy(n, c, X);
    xuat(n, c, X, cost);
    return 0;
}
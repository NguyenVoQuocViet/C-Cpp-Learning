#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#define swap(a, b, c) {(c) = (a); (a) = (b); (b) = (c);}
#define MAX 100

float m, m1, dg[MAX], w[MAX], v[MAX], x[MAX];

void init(int n)
{
    m1 = m;
    for (int i = 0; i < n; i++)
        dg[i] = v[i] / w[i];
    for (int i = 0; i < n - 1; i++)
    {
        float tmp;
        for (int j = i + 1; j < n; j++)
        {
            if (dg[i] < dg[j])
            {
                swap(dg[i], dg[j], tmp);
                swap(w[i], w[j], tmp);
                swap(v[i], v[j], tmp);
            }
        }
    }
}

// chon 1 do vat nhieu lan
void greedy(int n)
{
    int i = 0;
    while (i < n && m1 > 0)
    {
        if (m1 >= w[i])
        {
            m1 -= w[i];
            x[i]++;
        }
        else
            i++;
    }
}

void xuat(int n)
{
    float val = 0;
    float used_w = m - m1;
    printf("tong trong luong da dung: %.2f\n", used_w);
    for (int i = 0; i < n; i++)
    {
        if (x[i] != 0)
        {
            val += x[i] * v[i];
            printf("i: %d| x: %.0f| v: %4.2f| w: %4.2f\n", i, x[i], v[i], w[i]);
        }
    }
    printf("Gia tri lon nhat: %.2f voi tong truong luong: %.2f", val, used_w);
}

// chon 1 do vat 1 lan
void greedy2(int n)
{
    int i = 0;
    while (i < n && m1 > 0)
    {
        if (m1 >= w[i])
        {
            x[i] = 1;
            m1 -= w[i];
        }
        i++;
    }
}
int main()
{
    int n;
    printf("nhap so goi hang n: ");
    scanf("%d", &n);
    printf("nhap trong luong cai tui m: ");
    scanf("%f", &m);
    for (int i = 0; i < n; i++)
    {
        printf("nhap w[%d], v[%d]: ",i ,i);
        scanf("%f%f", &w[i], &v[i]);
    }
    init(n);
    // greedy(n);
    greedy2(n);
    xuat(n);
    return 0;
}
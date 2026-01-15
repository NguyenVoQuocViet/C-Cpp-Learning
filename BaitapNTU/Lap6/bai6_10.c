#include <stdio.h>
#define MAX 50

void xuat(float a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%.1f ", a[i]);
    }
    printf("\n");
}

int dem(float a[], int l, int r, float x)
{
    if (l == r)
    {
        return a[l] > x;
    }
    int m = (l + r) / 2;
    int cnt = 0;
    cnt += dem(a, l, m, x);
    cnt += dem(a, m + 1, r, x);
    return cnt;
}

float tongVTChan(float a[], int l, int r)
{
    if (l == r)
    {
        return (l % 2 == 0) ? a[l] : 0;
    }
    int m = (l + r) / 2;
    float left = tongVTChan(a, l, m);
    float right = tongVTChan(a, m + 1, r);
    return left + right;
}

int main()
{
    float a[] = {3.5, 7.1, 9.5, 1.1, 2.4};
    int n = sizeof(a) / sizeof(a[0]);
    xuat(a, n);
    float x;
    scanf("%f", &x);
    int cnt = dem(a, 0, n - 1, x);
    printf("%d\n", cnt);
    float sum = tongVTChan(a, 0, n - 1);
    printf("%.1f\n", sum);
    return 0;
}
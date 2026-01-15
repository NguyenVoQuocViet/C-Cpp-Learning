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

float timMax(float a[], int l, int r)
{
    if (l == r)
        return a[l];
    int m = (l + r) / 2;
    float left = timMax(a, l, m);
    float right = timMax(a, m + 1, r);
    if (left < right)
        return right;
    else
        return left;
}

float tongDuong(float a[], int l, int r)
{
    if (l == r)
    {
        return a[l] > 0 ? a[l] : 0;
    }
    int m = (l + r) / 2;
    float left = tongDuong(a, l, m);
    float right = tongDuong(a, m + 1, r);
    return left + right;
}

int main()
{
    float a[] = {3.5, 7.1, 9.5, 1.1, 2.4};
    int n = sizeof(a) / sizeof(a[0]);
    xuat(a, n);
    float _max = timMax(a, 0, n - 1);
    printf("%.1f\n", _max);
    float sum = tongDuong(a, 0, n - 1);
    printf("%.1f\n", sum);
    return 0;
}
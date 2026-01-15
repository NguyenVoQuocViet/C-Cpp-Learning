#include <stdio.h>
#define MAX 50

void xuat(int a[], int n){
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
}

int dayTangDan(int a[], int l, int r)
{
    if (l == r)
        return 1;
    int m = (l + r) / 2;
    int left = dayTangDan(a, l, m);
    int right = dayTangDan(a, m + 1, r);
    if (!left || !right)
        return 0;
    return a[m] <= a[m + 1];
}

int main()
{
    int a[] = {5, 7, 9, 11, 24, 10};
    int n = sizeof(a) / sizeof(a[0]);
    xuat(a, n);
    if (dayTangDan(a, 0, n - 1))
        printf("\nDay tang dan");
    else
        printf("\nDay khong tang dan");
    return 0;
}
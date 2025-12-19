#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define MAX 100

// cau a
int tinhTong(int a[], int l, int r)
{
    if (l > r)
        return 0;
    if (l == r)
        return a[l];
    int m = (l + r) / 2;
    int sum_left = tinhTong(a, l, m);
    int sum_right = tinhTong(a, m + 1, r);
    return sum_left + sum_right;
}
// cau b
int demX(int a[], int l, int r, int x)
{
    if (l > r)
        return 0;
    if (l == r)
        if (a[l] == x)
            return 1;
        else
            return 0;
    int m = (l + r) / 2;
    int count_left = demX(a, l, m, x);
    int count_right = demX(a, m + 1, r, x);
    return count_left + count_right;
}
// cau c
int min(int a[], int l, int r, int _min)
{
    if (l > r)
        return _min;
    if (l == r)
        return l;
    int m = (l + r) / 2;
    int min_left = min(a, l, m, _min);
    int min_right = min(a, m + 1, r, _min);
    _min = a[min_left] < a[min_right] ? min_left : min_right;
    return _min;
}

int main()
{
    int n;
    do
    {
        printf("nhap 5 < n < 100: ");
        scanf("%d", &n);
    } while (n <= 5 || n >= 100);
    int a[MAX];
    for (int i = 0; i < n; i++)
    {
        printf("a[%d]: ", i);
        scanf("%d", &a[i]);
    }

    int sum = tinhTong(a, 0, n - 1);
    printf("tong cac phan tu: %d\n", sum);

    int x;
    printf("nhap x: ");
    scanf("%d", &x);
    int cnt = demX(a, 0, n - 1, x);
    printf("so lan xuat hien cua %d: %d\n", x, cnt);

    int _min = min(a, 0, n - 1, INT_MAX);
    printf("vi tri phan tu nho nhat: %d", _min);
    return 0;
}
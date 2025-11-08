#include <stdio.h>
#include <stdlib.h>
#define MAX 50

void nhap(double a[], int *n)
{
    do
    {
        printf("nhap 2 <= n < 50: ");
        scanf("%d", n);
    } while (*n < 2 || *n > 50);
    for (int i = 0; i < *n; i++)
    {
        printf("nhap a[%d]: ", i);
        scanf("%lf", &a[i]);
    }
}

double tongVTLe(double a[], int n)
{
    if (n == 0)
        return 0.0;
    if ((n - 1) % 2 == 1)
        return tongVTLe(a, n - 1) + a[n - 1];
    return tongVTLe(a, n - 1);
}

double tich(double a[], int n)
{
    if (n == 0)
        return 1;
    return a[n - 1] * tich(a, n - 1);
}

int dem(double a[], int n, double x)
{
    if (n == 0)
        return 0;
    if (a[n - 1] > x)
        return dem(a, n - 1, x) + 1;
    return dem(a, n - 1, x);
}

int dayDuong(double a[], int n)
{
    if (n == 0)
        return 1;
    if (a[n - 1] <= 0)
        return 0;
    return dayDuong(a, n - 1);
}

int main()
{
    int n;
    double a[MAX];
    nhap(a, &n);

    printf("tong cac phan tu o vi tri le: %.2lf\n", tongVTLe(a, n));

    printf("tich cac phan tu: %.2lf\n", tich(a, n));

    printf("nhap 1 gia tri: ");
    double x;
    scanf("%lf", &x);
    printf("so phan tu lon hon %.2lf: %d\n", x, dem(a, n, x));

    if (dayDuong(a, n))
        printf("day toan so duong");
    else   
        printf("day khong toan so duong");
    return 0;
}

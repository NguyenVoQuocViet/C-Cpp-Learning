#include <stdio.h>
#include <stdlib.h>
#define MAX 101
#define max(a, b) (a) > (b) ? (a) : (b)
#define max3(a, b, c) (max((c), max((b), (c))))

void nhap(int a[], int* n)
{
    do
    {
        printf("nhap 5 < n < 100: ");
        scanf("%d", n);
    } while (*n <= 5 || *n >= 100);
    for (int i = 0; i < *n; i++)
    {
        printf("a[%d]: ", i);
        scanf("%d", &a[i]);
    }
}

// cau a
int timX(int a[], int l, int r, int x)
{
    if (l <= r)
    {
        int m = (l + r) / 2;
        if (a[m] == x)
            return m;
        else if (a[m] > x)
            return timX(a, l, m - 1, x);
        else
            return timX(a, m + 1, r, x);
    }
    return -1;
}

// cau b
int demX(int a[], int l, int r, int x)
{
    if (l > r)
        return 0;
    if (l == r)
        return a[l] == x;
    int m = (l + r) / 2;
    int left = demX(a, l, m, x);
    int right = demX(a, m + 1, r, x);    
    return left + right;
}

// cau c
int timMax(int a[], int l, int r, int _max)
{
    if (l > r)
        return _max;
    if (l == r)
        return a[l];
    int m = (l + r) / 2;
    int left = timMax(a, l, m, _max);
    int right = timMax(a, m + 1, r, _max);
    _max = max(left, right);
    return _max;
}

// cau d
int tongGiua(int a[], int l, int m, int r)
{
    int sum = 0;
    int left = INT_MIN;
    for (int i = m; i >= l; i--)
    {
        sum += a[i];
        left = max(left, sum);
    }
    sum = 0;
    int right = INT_MIN;
    for (int i = m + 1; i <= r; i++)
    {
        sum += a[i];
        right = max(right, sum);
    }
    return left + right;
}

int tongMax(int a[], int l, int r)
{
    if (l == r)
        return a[l];
    int m = (l + r) / 2;
    return max3(tongMax(a, l, m), tongMax(a, m + 1, r), tongGiua(a, l, m, r));
}

int main()
{
    int n, a[MAX], x;
    nhap(a, &n);
    printf("nhap x: ");
    scanf("%d", &x);

    // cau a
    int pos1 = timX(a, 0, n - 1, x);
    printf("vi tri: %d\n", pos1);

    // cau b
    int cnt = demX(a, 0, n - 1, x);
    printf("so phan tu: %d\n", cnt);

    // cau c
    int _max = timMax(a, 0, n - 1, INT_MIN);
    printf("so lon nhat: %d\n", _max);

    // cau d
    int max_sum = tongMax(a, 0, n - 1);
    printf("tong con lon nhat: %d", max_sum);
    return 0;
}
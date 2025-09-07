#include <stdio.h>
#include <stdlib.h>

int binarySearch1(int* a, int l, int r, int x) //de quy
{
    if(l <= r)
    {
        int m = l + (r - l)/2;
        if(a[m] < x)
            return binarySearch1(a, m + 1, r, x);
        else if(a[m] > x)
            return binarySearch1(a, l, m-1, x);
        else 
            return 1;
    }
    return 0;
}

int binarySearch2(int* a, int n, int x)
{
    int l = 0, r = n - 1;
    while(l <= r)
    {
        int m = (l+r)/2;
        if(a[m] == x)
            return 1;
        else
        {
            if(a[m] < x)
                l = m + 1;
            else
                r = m - 1;
        }
    }
    return 0;
}

int bS_First(int* a, int n, int x) //tim chi so dau tien
{
    int l = 0, r = n - 1, res = -1;
    while(l <= r)
    {
        int m = (l + r)/2;
        if(a[m] == x)
        {
            res = m;
            r = m - 1;
        }
        else
        {
            if(a[m] > x)
                r = m - 1;
            else
                l = m + 1;
        }
    }
    return res;
}

int bS_Last(int* a, int n, int x) //tim chi so cuoi cung
{
    int l = 0, r = n - 1, res = -1;
    while(l <= r)
    {
        int m = (l + r)/2;
        if(a[m] == x)
        {
            res = m;
            l = m + 1;
        }
        else
        {
            if(a[m] > x)
                r = m - 1;
            else
                l = m + 1;
        }
    }
    return res;
}

int bS_GreaterEqual(int* a, int n, int x) //tim phan tu dau tien lon hon hoac bang x
{
    int l = 0, r = n - 1, res = -1;
    while(l <= r)
    {
        int m = (l + r) / 2;
        if(a[m] >= x)
        {
            res = m;
            r = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }
    return res;
}

int bS_SmallerEqual(int* a, int n, int x) //tim phan tu cuoi cung nho hon hoac bang x
{
    int l = 0, r = n - 1, res = -1;
    while(l <= r)
    {
        int m = (l + r) / 2;
        if(a[m] <= x)
        {
            res = m;
            l = m + 1;
        }
        else
            r = m - 1;
    }
    return res;
}

int main()
{
    int n, x;
    scanf("%d%d", &n, &x);
    int *a = (int *)malloc(n*sizeof(int));
    for(int i = 0; i<n; i++)
        scanf("%d", &a[i]);
    //printf("%d", binarySearch1(a, 0, n-1, x));
    printf("%d", bS_SmallerEqual(a, n, x));
    free(a);
    return 0;
}
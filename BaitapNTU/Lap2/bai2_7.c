#include <stdio.h>
#include <math.h>
#define MAX 50

void docSN(const char* s, int a[], int *n)
{
    FILE* f = fopen(s, "r");
    if(f != NULL)
    {
        int x;
        while(fscanf(f, "%d", &x) != -1)
        {
            a[(*n)++] = x;
        }
    }
    else
        printf("NOT OPEN FILE!");
}

void xuat(int a[], int n)
{
    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int snt(int n)
{
    for(int i = 2; i <= sqrt(n); i++)
    {
        if(n % i == 0)
            return 0;
    }
    return n > 1;
}

int tong(int a[], int n)
{
    int sum = 0;
    for(int i = 0; i < n; i++)
        if(snt(a[i]))
            sum += a[i];
    return sum;
}

int main()
{
    int n = 0, a[MAX];
    const char* s = "DaySoNguyen.txt";
    docSN(s, a, &n);
    xuat(a, n);
    printf("tong cac phan tu la so nguyen to la: %d", tong(a, n));
    return 0;
}
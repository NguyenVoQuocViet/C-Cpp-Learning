#include <stdio.h>
#define MAX 50

void nhap(int a[], int *n)
{
    do
    {
        printf("nhap 3 < n < 50: ");
        scanf("%d", n);
    }while(*n <= 3 || *n >= 50);
    int i;
    for(i = 0; i < *n; i++)
    {
        printf("a[%d]: ", i);
        scanf("%d", &a[i]);
    }
}

int timChan(int a[], int n)
{
    int linhcanh = 0;
    a[n] = linhcanh;
    int i = 0;
    while(a[i] % 2 != 0)
    {
        i++;
    }
    if(i == n)
        return -1;
    else
        return a[i];
}

int dayGiamDan(int a[], int n)
{
    int i, check = 1;
    for(int i = 0; i < n - 1; i++)
    {
        if(a[i] < a[i + 1])
        {
            check = 0;
            break;
        }
    }
    return check;
}

int main()
{
    int n;
    int a[MAX];
    nhap(a, &n);
    int chan = timChan(a, n);
    if(chan == -1)
        printf("khong co so chan\n");
    else
        printf("so chan dau tien la: %d\n", chan);
    if(dayGiamDan(a, n))
        printf("day giam dan\n");
    else  
        printf("day khong giam dan\n");
    return 0;
}
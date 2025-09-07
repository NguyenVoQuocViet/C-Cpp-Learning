#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//sap xep chen
void insert_sort(int a[], int n)
{
    for(int i = 1; i<n; i++)
    {
        int insert_value = a[i];
        int insert_pos = i - 1;
        while(insert_pos >= 0 && a[insert_pos] > insert_value)
        {
            a[insert_pos + 1] = a[insert_pos];
            insert_pos--;
        }
        a[insert_pos + 1] = insert_value;
    }
}
//sap xep dem
void counting_sort(int a[], int n)
{
    int k = -1e9;
    for(int i = 0; i<n; i++)
    {
        k = fmax(k, a[i]);
    }
    int *cnt = (int *)calloc((k+1), sizeof(int));
    for(int i = 0; i<n; i++)
    {
        cnt[a[i]]++;
    }
    for(int i = 0; i<=k; i++)
    {
        while(cnt[i] > 0)
        {
            printf("%d ", i);
            cnt[i]--;
        }
    }
    free(cnt);
}
//tron
void merge(int a[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
    int left[n1], right[n2];
    for(int i = 0; i<n1; i++)
    {
        left[i] = a[l + i];
    }
    for(int i = 0; i<n2; i++)
    {
        right[i] = a[m + 1 + i]; 
    }
    int i = 0, j = 0, k = l;
    while(i < n1 && j < n2)
    {   
        if(left[i] <= right[j])
        {
            a[k++] = left[i++];
        }
        else
        {
            a[k++] = right[j++];
        }
    }
    while(i < n1)
        a[k++] = left[i++];
    while(j < n2)
        a[k++] = right[j++];
}
//sap xep tron
void merge_sort(int a[], int l, int r)
{
    if(l < r)
    {
        int m = l + (r - l)/2;
        merge_sort(a, l, m);
        merge_sort(a, m + 1, r);
        merge(a, l, m, r);
    }
}
//phan hoach
int partition(int a[], int l, int r)
{
    int i = l - 1, pivot = a[r];
    for(int j = l; j<r; j++)
    {
        if(a[j] <= pivot)
        {
            i++;
            int tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
        }
    }
    i++;
    int tmp = a[i];
    a[i] = a[r];
    a[r] = tmp;
    return i;
}
//sap xep nhanh
void quick_sort(int a[], int l, int r)
{
    if(l < r)
    {
        int pos = partition(a, l, r);
        quick_sort(a, l, pos - 1);
        quick_sort(a, pos + 1, r);
    }
}
//qsort
int sum(int a)
{
    if(a == 0) return 0;
    else
        return a%10 + sum(a/10);
}

int cmp(const void *a, const void *b)
{
    int *x = (int*)a;
    int *y = (int*)b;
    if(sum(*x) == sum(*y))
    {
        return *x - *y;
    }
    else
        return sum(*x) - sum(*y);
}
int main()
{
    int n;
    scanf("%d", &n);
    int *a = (int *)malloc(n*sizeof(int));
    for(int i = 0; i<n; i++)
    {
        scanf("%d", &a[i]);
    }
    //insert_sort(a, n);
    //counting_sort(a, n);
    //merge_sort(a, 0, n-1);
    //quick_sort(a, 0, n-1);
    qsort(a, n, sizeof(int), cmp);
    for(int i = 0; i<n; i++)
    {
        printf("%d ", a[i]);
    }
    free(a);
    return 0;
}
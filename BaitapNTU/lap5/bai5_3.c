#include <stdio.h>
#include <stdlib.h>
#define MAX 50

void readFile(int a[], int* n, int* M)
{
    FILE* fin = fopen("input.txt", "r");
    if (fin != NULL)
    {
        fscanf(fin, "%d", n);
        if (*n < 2 || *n > 20)
        {
            printf("n khong hop le!");
            return;
        }
        fscanf(fin, "%d", M);
        for (int i = 0; i < *n; i++)
            fscanf(fin, "%d", &a[i]);
        fclose(fin);
    }
    else
        printf("NOT OPEN FILE!");
}

int cmp(const void* a, const void* b)
{
    return *(int*)b - *(int*)a;
}

void weightGreedy(int a[], int n, int M)
{
    qsort(a, n, sizeof(int), cmp);
    int weight = 0, w[MAX];
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (M >= a[i])
        {
            if (weight + a[i] <= M)
            {
                weight += a[i];
                w[j++] = a[i];
            }
        }
    }
    FILE* fout = fopen("output.txt", "w");
    if (M == weight)
    {
        fprintf(fout, "%d\n", j);
        for (int i = 0; i < j; i++)
            fprintf(fout, "%d ", w[i]);
    }
    else    
        fprintf(fout, "Khong chon duoc");
    fclose(fout);
}

int main()
{
    int n, M;
    int a[MAX];
    readFile(a, &n, &M);
    weightGreedy(a, n, M);
    return 0;
}
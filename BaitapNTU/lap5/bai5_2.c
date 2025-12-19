#include <stdio.h>
#include <stdlib.h>
#define MAX 50

void readFile(int a[], int *n, int *s)
{
    FILE *fin = fopen("ATM.txt", "r");
    if (fin != NULL)
    {
        fscanf(fin, "%d", n);
        if (*n >= 30)
        {
            printf("n khong hop le!");
            return;
        }
        fscanf(fin, "%d", s);
        for (int i = 0; i < *n; i++)
            fscanf(fin, "%d", &a[i]);
        fclose(fin);
    }
    else
        printf("NOT OPEN FILE!");
}

int cmp(const void *a, const void *b)
{
    return *(int *)b - *(int *)a;
}

void atmGreedy(int a[], int n, int s)
{
    qsort(a, n, sizeof(int), cmp);
    int tien[MAX], curr = 0;
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (s >= a[i])
        {
            if (curr + a[i] <= s)
            {
                tien[j++] = a[i];
                curr += a[i];
            }
        }
        if (curr == s)
            break;
    }
    FILE *fout = fopen("atm_out.txt", "w");
    if (s == curr)
    {
        for (int i = 0; i < j; i++)
        {
            fprintf(fout, "%d ", tien[i]);
        }
        fprintf(fout, "\nTong so to tien la: %d", j);
    }
    else
        fprintf(fout, "Khong chon duoc");
    fclose(fout);
}
int main()
{
    int n, s;
    int a[MAX];
    readFile(a, &n, &s);
    atmGreedy(a, n, s);
    return 0;
}
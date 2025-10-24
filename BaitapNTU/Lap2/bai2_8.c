#include <stdio.h>
#include <string.h>

#define MAX 50
struct SV
{
    int mssv;
    char hoten[100];
    int nam;
};
typedef struct SV SV;

void nhap(const char* s, int *n)
{
    do
    {
        printf("nhap 2 <= n < 50: ");
        scanf("%d", n);
    }while(*n < 2 || *n >= 50);
    FILE* f = fopen(s, "w");
    if(f != NULL)
    {
        SV sv;
        for(int i = 0; i < *n; i++)
        {
            printf("nhap MSSV %d: ", i + 1);
            scanf("%d", &sv.mssv);
            getchar();
            printf("nhap ho ten sinh vien %d: ", i + 1);
            fgets(sv.hoten, 100, stdin);
            sv.hoten[strlen(sv.hoten) - 1] = '\0';
            printf("nhap nam sinh sinh vien %d: ", i + 1);
            scanf("%d", &sv.nam);
            getchar();
            fprintf(f, "%d\n%s\n%d\n", sv.mssv, sv.hoten, sv.nam);
        }
        fclose(f);
    }
    else
        printf("NOT OPEN FILE!");    
}

void svThuP(const char* s, SV sv[], int n)
{
    int p;
    printf("nhap p: ");
    scanf("%d", &p);
    getchar();
    if(p < 1 || p > n)
    {
        printf("chi so khong hop le\n");
        return;
    }
    else
        p--;
    FILE* f = fopen(s, "r");
    if(f != NULL)
    {
        for(int i = 0; i < n; i++)
        {
            fscanf(f, "%d\n", &sv[i].mssv);
            fgets(sv[i].hoten, 100, f);
            sv[i].hoten[strlen(sv[i].hoten) - 1] = '\0';
            fscanf(f, "%d\n", &sv[i].nam);
        }
        printf("%d\n%s\n%d\n",sv[p].mssv, sv[p].hoten, sv[p].nam);
        fclose(f);
    }
    else
        printf("NOT OPEN FILE");
}

int main()
{
    int n;
    SV sv[MAX];
    const char* s = "SinhVien.inp";
    nhap(s, &n);
    svThuP(s, sv, n);
    return 0;
}
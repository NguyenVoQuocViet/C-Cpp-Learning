#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
ý tưởng:
- sắp xếp các hạot động tăng dần theo thời gian kết thúc tăng dần
- chọn hoạt động đầu tiên, sau đó chọn các hoạt động tiếp theo sao cho
thời gian bắt đầu hoạt động đó >= thời gian kết thúc hoạt động đã chọn trước
*/

int cmp(const void* a, const void* b)
{
    int* x = (int*)a;
    int* y = (int*)b;
    if (x[1] != y[1])
        return x[1] - y[1];
    else
        return x[0] - y[0];
}

int main()
{
    int n;
    printf("nhap so hoat dong: ");
    scanf("%d", &n);
    int hd[n][2];
    for (int i = 0; i < n; i++)
    {
        printf("bat dau hd[%d]: ", i + 1);
        scanf("%d", &hd[i][0]);
        printf("ket thuc hd[%d]: ", i + 1);
        scanf("%d", &hd[i][1]);
    }
    qsort(hd, n, sizeof(hd[0]), cmp);
    int dem = 1, tmp = hd[0][1];
    for (int i = 1; i < n; i++)
    {
        if (hd[i][0] >= tmp)
        {
            dem++;
            tmp = hd[i][1];
        }
    }
    printf("so luong hoat dong lon nhat: %d", dem);
    return 0;
}
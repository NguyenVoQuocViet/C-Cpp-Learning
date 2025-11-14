#include <stdio.h>
#include <stdlib.h>

/*
ý tưởng: 
- chia mảng thành 2 nửa [1, n]
- đệ quy tính tổng nửa trái
- đệ quy tính tổng nửa phải
- tổ hợp kết quả hai nửa
*/

int tong(int l, int r)
{
    if (l > r)
        return 0;
    if (l == r)
        return l * l;
    int m = (l + r) / 2;
    l = tong(l, m);
    r = tong(m + 1, r);
    return l + r;
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d", tong(1, n));
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define ll long long

void nhapN(int *n, int a, int b);
ll giaithua(int n);
void doiCoSo2(int n);
ll soPell(int n);
double tongND(int n);
ll tongLT(int n);
int gcd(int a, int b);
ll tongGT(int n);
int fibo(int n);
ll sumFibo(int n);
double tong1(int n);
int tong2(int n);

int main()
{
    int n;

    // cau a
    nhapN(&n, 0, 20);
    printf("%d! = %lld\n", n, giaithua(n));

    // cau b
    printf("doi %d sang co so 2: ", n);
    doiCoSo2(n);

    // cau c
    printf("\nso Pell thu %d la: %lld\n", n, soPell(n));

    // cau d
    nhapN(&n, 1, 101);
    printf("tong nghich dao: %.2lf\n", tongND(n));

    // cau e
    nhapN(&n, 0, 10);
    printf("tong luy thua: %lld\n", tongLT(n));

    // cau f
    printf("nhap 2 so nguyen: ");
    int a, b;
    scanf("%d%d", &a, &b);
    printf("uoc chung lon nhat cua %d va %d: %d\n", a, b, gcd(a, b));

    // cau g
    nhapN(&n, 1, 11);
    printf("tong giai thua: %lld\n", tongGT(n));

    // cau h
    nhapN(&n, 1, 31);
    printf("tong %d so fibonacci dau tien: %lld\n", n, sumFibo(n));

    // cau i
    nhapN(&n, 1, 31);
    printf("tong la: %.2lf\n", tong1(n));

    // cau j
    nhapN(&n, 1, 11);
    printf("tong la: %d\n", tong2(n));
    return 0;
}

void nhapN(int *n, int a, int b)
{
    do
    {
        printf("nhap %d < n < %d: ", a, b);
        scanf("%d", n);
    } while (*n <= a || *n >= b);
}

// cau a
ll giaithua(int n)
{
    if (n == 1)
        return 1;
    return n * giaithua(n - 1);
}

// cau b
void doiCoSo2(int n)
{
    if (n == 0)
        return;
    doiCoSo2(n / 2);
    printf("%d", n % 2);
}

// cau c
ll soPell(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return 2 * soPell(n - 1) + soPell(n - 2);
}

// cau d
double tongND(int n)
{
    if (n == 2)
        return 0.5;
    return tongND(n - 1) + 1.0 / n;
}

// cau e
ll tongLT(int n)
{
    if (n == 1)
        return 1;
    return pow(n, n + 1) + tongLT(n - 1);
}

// cau f
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// cau g
ll tongGT(int n)
{
    if (n == 1)
        return 1;
    return giaithua(n) + tongGT(n - 1);
}

// cau h
int fibo(int n)
{
    int f[20] = {0};
    f[1] = 1;
    for(int i = 2; i <= n; i++)
        f[i] = f[i - 1] + f[i - 2];
    return f[n];
}   

ll sumFibo(int n)
{
    if (n == 1)
        return 1;
    return fibo(n) + sumFibo(n - 1);
}

// cau i
double tong1(int n)
{
    if (n == 1)
        return 0.5;
    return 1.0*n/(n+1) + tong1(n - 1);
}

// cau j
int tong2(int n)
{
    if (n == 1)
        return 2;
    return n * (n + 1) + tong2(n - 1);
}
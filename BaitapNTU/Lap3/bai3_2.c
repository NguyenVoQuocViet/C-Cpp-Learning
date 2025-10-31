#include <stdio.h>
#include <math.h>
void nhapN(int *n, int a, int b)
{
	do
	{
		printf("nhap %d <= n < %d: ", a, b);
		scanf("%d", n);
	}while(*n < a || *n > b);
}
//cau a
int tongChan(int n)
{
	if(n == 2)
		return 2;
	return n + tongChan(n - 2);
}
//cau b
int tongChuSo(int n)
{
	if(n < 10)
		return n;
	return n % 10 + tongChuSo(n / 10);
}
//cau c
int tongDSHH(int n,int a, int r)
{
	if(n == 0)
		return a;
	return a*pow(r, n) + tongDSHH(n - 1, r, a);
}
//cau d
int tongChiaHetBa(int n)
{
	if(n == 0)
		return 0;
	return n % 3 == 0 ? n + tongChiaHetBa(n - 1) : tongChiaHetBa(n - 1);
}
//cau e
double tongPhanSo(int n)
{
	if(n == 1)
		return 1.0;
	return 1.0/n + tongPhanSo(n - 1);
}
int main()
{
	int n;
	//cau a
	nhapN(&n, 2, 50);
	printf("tong cac so chan la: %d\n",tongChan(n));
	
	//cau b
	nhapN(&n, 1000, 1000000);
	printf("tong chu so la: %d\n", tongChuSo(n));
	
	//cau c
	nhapN(&n, 2, 10);
	int a, r;
	printf("nhap a va r: ");
	scanf("%d%d", &a, &r);
	printf("tong day so hinh hoc la: %d\n", tongDSHH(n, a, r));
	
	//cau d
	nhapN(&n, 2, 500);
	printf("tong cac so chia het cho 3: %d\n", tongChiaHetBa(n));
	
	//cau e
	nhapN(&n, 2, 50);
	printf("tong day phan so: %.2lf", tongPhanSo(n));
}

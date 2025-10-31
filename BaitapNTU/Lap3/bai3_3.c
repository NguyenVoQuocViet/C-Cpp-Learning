#include <stdio.h>
#include <math.h>
#define MAX 50

void nhap(int a[], int n, int i)
{
	if(i == n)
		return;
	printf("nhap a[%d]: ", i);
	scanf("%d", &a[i]);
	nhap(a, n, i + 1);
}

int demChan(int a[], int n)
{
	if(n == 0)
		return 0;
	if(a[n - 1] % 2 == 0)	
		return 1 + demChan(a, n - 1);
	else
		return demChan(a, n - 1);
}

int snt(int n)
{
	int i;
	for(i = 2; i <= sqrt(n); i++)
		if(n % i == 0)
			return 0;
	return n > 1;
}

int checkSNT(int a[], int n)
{
	if(n == 0)
		return 0;
	if(snt(a[n - 1]))
		return 1;
	return checkSNT(a, n - 1);
}

int viTriX(int a[], int n, int i, int x)
{
	if(i == n)
		return -1;
	if(a[i] == x)
		return i;
	else
		return viTriX(a, n, i + 1, x);
} 

void thapHaNoi(int n, char a, char b, char c)
{
	if(n == 1)
	{
		printf("chuyen 1 dia tu %c sang %c\n", a, c);
	}
	else
	{
		thapHaNoi(n - 1, a, c, b);
		thapHaNoi(1, a, b, c);
		thapHaNoi(n - 1, b, a, c);
	}
}
int main()
{
	int n, a[MAX];
	do
	{
		printf("nhap 2 <= n < 50: ");
		scanf("%d", &n);
	}while(n < 2 || n >= 50);
	nhap(a, n, 0);
	
	printf("so phan tu chan trong day: %d\n", demChan(a, n));
	
	if(checkSNT(a, n))
		printf("day co chua so nguyen to\n");
	else
		printf("day khong chua so nguyen to\n");
	
	int x;
	printf("nhap x: ");
	scanf("%d", &x);
	int pos = viTriX(a, n, 0, x);
	if(pos == -1)
		printf("khong co phan tu %d\n", x);
	else
		printf("vi tri dau tien cua %d: %d\n", x, pos);
		
	thapHaNoi(n, 'A', 'B', 'C');
}

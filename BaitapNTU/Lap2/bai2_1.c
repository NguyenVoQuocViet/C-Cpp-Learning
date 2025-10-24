#include <stdio.h>
#define MAX 50

void nhap(int a[], int *n)
{
	do
	{
		printf("nhap 3 < n < 50: ");
		scanf("%d", n);
	}while((*n) <= 3 || (*n) >= 50);
	int i;
	for(i = 0; i < (*n); i++)
	{
		printf("nhap a[%d]: ", i);
		scanf("%d", &a[i]);
	}
}

void timSoAm(int a[], int n)
{
	int i = 0;
	int linhcanh = -1;
	a[n] = linhcanh;
	while(a[i] >= 0)
	{
		i++;
	}
	if(i == n)
		printf("khong co so am\n");
	else
		printf("so am dau tien: %d %d\n", i, a[i]);
}

int timX(int a[], int n, int x)
{
	a[n] = x;
	int i = 0;
	while(a[i] != x)
	{
		i++;
	}
	return i != n;		
}

int dayGiamDan(int a[], int n)
{
	int flag = 0, i;
	for(i = 0; i < n - 1; i++)
	{
		if(a[i] < a[i + 1])
		{
			flag = 1;
			break;
		}
	}
	return flag == 0;
}

int nguyenDuong(int a[], int n)
{
	int check = 0, i;
	for(i = 0; i < n; i++)
		if(a[i] < 0)
		{
			check = 1;
			break;
		}
	return check == 0;
} 

int main()
{
	int n, i;
	int a[MAX];
	nhap(a, &n);
	
	timSoAm(a, n);
	
	int x;
	printf("nhap x: ");
	scanf("%d", &x);
	if(timX(a, n, x))
		printf("%d co xuat hien trong mang\n", x);
	else
		printf("%d khong xuat hien trong mang\n", x);
		
	if(dayGiamDan(a, n))
	{
		printf("Day giam dan\n");
	}
	else
	{
		printf("Day khong giam dan\n");
	}
	
	if(nguyenDuong(a, n))
		printf("Day toan so nguyen duong\n");
	else
		printf("Day khong toan so nguyen duong\n");
}

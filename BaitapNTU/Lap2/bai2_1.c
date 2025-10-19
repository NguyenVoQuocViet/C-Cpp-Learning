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
	int check = 0, i;
	for(i = 0; i < n; i++)
	{
		if(a[i] < 0)
		{
			printf("vi tri: %d, gia tri: %d\n", i, a[i]);
			check = 1;
			break;
		}
	}
	if(!check)
	{
		printf("Khong co so am\n");
	}
}

int timX(int a[], int n, int x)
{
	int check = 0, i;
	for(i = 0; i < n; i++)
	{
		if(x == a[i])
		{
			check = 1;
			break;
		}
	}
	return check;
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

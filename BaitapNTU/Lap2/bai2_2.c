#include <stdio.h>
#include <stdlib.h>

void ngauNhien(char *s, int *n)
{
	FILE *f = fopen(s, "w");
	if(f != NULL)
	{
		int i;
		do
		{
			printf("nhap 2 <= n <= 30: ");
			scanf("%d", n);
		}while((*n) < 2 || (*n) > 30);
		for(i = 0; i < (*n); i++)
		{
			int number = rand() % 1001;
			fprintf(f, "%d ", number);
		}
		fclose(f);
	}
	else
	{
		printf("NOT OPEN FILE!");
	}
}

void readFile(char *s, int a[], int n)
{
	FILE *f = fopen(s, "r");
	if(f != NULL)
	{
		int i = 0;
		for(i = 0; i < n; i++)
		{
			fscanf(f, "%d", &a[i]);
		}
		fclose(f);
	}
	else
	{
		printf("NOT OPEN FILE!");
	}
}

void writeFile(int a[], int n)
{
	int i;
	for(i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
}

int tongNguyenDuong(int a[], int n)
{
	int sum = 0, i;
	for(i = 0; i < n; i++)
	{
		if(a[i] > 0 && a[i] % 2 == 0)	
			sum += a[i];
	}
	return sum;
}

int main()
{
	srand(time(NULL));
	char *s = "DaySo.txt";
	int n;
	ngauNhien(s, &n);
	int a[n];
	readFile(s, a, n);
	writeFile(a, n);
	printf("Tong so nguyen duong chan: %d", tongNguyenDuong(a, n));
	return 0;
}

#include <stdio.h>

void taoFile(char *s, int *n)
{
	FILE *f = fopen(s, "w");
	if(f != NULL)
	{
		do
		{
			printf("nhap 3 <= n <= 40: ");
			scanf("%d", n);
		}while((*n) < 3 || (*n) > 40);
		int i;
		for(i = 0; i < (*n); i++)
		{
			printf("nhap a[%d]: ", i);
			float num;
			scanf("%f", &num);
			fprintf(f, "%.2f ", num);
		}
		fclose(f);
	}
	else
	{
		printf("NOT OPEN FILE!");
	}
}

void nhap(char *s, float a[] ,int n)
{
	FILE *f = fopen(s, "r");
	if(f != NULL)
	{
		int i;
		for(i = 0; i < n; i++)
		{
			fscanf(f, "%f", &a[i]);
		}
		fclose(f);
	}
	else
	{
		printf("NOT OPEN FILE!");
	}
}

void xuat(float a[], int n)
{
	int i;
	for(i = 0; i < n; i++)
	{
		printf("%.2f ", a[i]);
	}
}

int dem(float a[], int n, int x)
{
	int i, cnt = 0;
	for(i = 0; i < n; i++)
	{
		if(a[i] < x)
			cnt++;
	}
	return cnt;
	
}
int main()
{
	char *s = "DaySo2_4.txt";
	int n;
	taoFile(s, &n);
	float a[n];
	nhap(s, a, n);
	xuat(a, n);
	float x;
	printf("nhap x:");
	scanf("%f", &x);
	printf("\nso luong phan tu nho hon %.2f: %d", x, dem(a, n, x));
	return 0;
}

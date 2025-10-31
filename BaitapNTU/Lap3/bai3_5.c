#include <stdio.h>
#define MAX 50

void readFile(char* s, double a[], int* n)
{
	FILE* f = fopen(s, "r");
	if(f != NULL)
	{
		fscanf(f, "%d", n);
		if(*n < 2 || *n > 50)
		{
			printf("n khong hop le!");
			return;
		}
		int i;
		for(i = 0; i < *n; i++)
		{
			fscanf(f, "%lf", &a[i]);
		}
		fclose(f);
	}
	else
		printf("NOT OPEN FILE!");
}

void xuat(double a[], int n)
{
	int i;
	for(i = 0; i < n; i++)
	{
		printf("%.4lf ", a[i]);
	}
	printf("\n");
}
int main()
{
	char* s = "DaySo35.txt";
	int n;
	double a[MAX];
	readFile(s, a, &n);
	xuat(a, n);
}

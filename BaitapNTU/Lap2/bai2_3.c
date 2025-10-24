#include <stdio.h>
#define MAX 20
#define MAXAB(a, b) ((a) > (b) ? (a) : (b))

void writeFile(char *s, int *n)
{
	FILE *f = fopen(s, "w");
	if(f != NULL)
	{
		do
		{
			printf("nhap 2 <= n <= 20: ");
			scanf("%d", n);
		}while((*n) < 2 || (*n) > 20);
		int i, j;
		for(i = 0; i < (*n); i++)
		{
			for(j = 0; j < (*n); j++)
			{
				printf("nhap a[%d][%d]: ", i, j);
				int num;
				scanf("%d", &num);
				fprintf(f, "%d ", num);
			}
			fprintf(f, "\n");
		}
		fclose(f);
	}
	else
	{
		printf("NOT OPEN FILE!");
	}
}

void readMatrix(char *s, int a[][MAX], int n)
{
	FILE *f = fopen(s, "r");
	if(f != NULL)
	{
		int num, i, j;
		for(i = 0; i < n; i++)
		{
			for(j = 0; j < n; j++)
			{
				fscanf(f, "%d", &a[i][j]);
			}
		}
		fclose(f);
	}
	else
	{
		printf("NOT OPEN FILE!");
	}
}

void writeMatrix(int a[][MAX], int n)
{
	printf("so phan tu: %d\n", n);
	int i, j;
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}

void tongMax(char *kq, int a[][MAX], int n)
{
	FILE *f = fopen(kq, "w");
	int sum = 0, i, j;
	for(i = 0; i < n; i++)
	{
		sum += a[i][i];
	}
	fprintf(f, "%d\n", sum);
	fclose(f);
}

void timMax(char *kq, int a[][MAX], int n)
{
	FILE *f = fopen(kq, "a");
	int i, j, max = -1e9;
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			max = MAXAB(max, a[i][j]);
		}
	}
	fprintf(f, "%d\n", max);
	fclose(f);
}

int main()
{
	int n;
	char *s = "MaTran.inp";
	char *kq = "KetQua.out";
	writeFile(s, &n);
	int a[MAX][MAX];
	readMatrix(s, a, n);
	writeMatrix(a, n);
	tongMax(kq, a, n);
	timMax(kq, a, n);
	return 0;
}

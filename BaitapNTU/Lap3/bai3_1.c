#include <stdio.h>
#define MAX 50

void readFile(char* s, int a[], int *n)
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
			fscanf(f, "%d", &a[i]);
		}
		fclose(f);
	}
	else
	{
		printf("NOT OPEN FILE!");
	}
}

void xuat(int a[], int n)
{
	int i;
	for(i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
}

int maxNumDQ(int a[], int n)
{
	if(n == 0)
		return -1e9;
	int max = maxNumDQ(a, n - 1);
	return max < a[n - 1] ? a[n - 1] : max;
}

int maxVL(int a[], int n)
{
	int max = -1e9, i;
	for(i = 0; i < n; i++)
	{
		if(a[i] > max)
			max = a[i];
	}
	return max;
}

int main()
{
	char* s = "Lap3_1.txt";
	int n, a[MAX];
	readFile(s, a, &n);
	xuat(a, n);
	printf("\nso lon nhat (de quy): %d", maxNumDQ(a, n));
	printf("\nso lon nhat (vong lap): %d", maxVL(a, n));
	return 0;
}

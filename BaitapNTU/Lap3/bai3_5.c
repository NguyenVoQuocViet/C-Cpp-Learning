#include <stdio.h>
#include <stdlib.h>
#define MAX 50

void readFile(const char *s, double a[], int *n)
{
	FILE *f = fopen(s, "r");
	if (f != NULL)
	{
		fscanf(f, "%d", n);
		if (*n < 2 || *n > 50)
		{
			printf("n khong hop le!");
			return;
		}
		int i;
		for (i = 0; i < *n; i++)
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
	for (i = 0; i < n; i++)
	{
		printf("%.4lf ", a[i]);
	}
	printf("\n");
}

double minNumDQ(double a[], int n, double _min)
{
	if (n == 0)
		return _min;
	return (_min > a[n - 1]) ? minNumDQ(a, n - 1, a[n - 1]) : minNumDQ(a, n - 1, _min);
}

double minNumVL(double a[], int n)
{
	double _min = 1e18;
	for (int i = 0; i < n; i++)
	{
		if (_min > a[i])
			_min = a[i];
	}
	return _min;
}

double tongDQDau(double a[], int n)
{
	if (n == 0)
		return 0.0;
	return a[n - 1] + tongDQDau(a, n - 1);
}

double tongDQDuoi(double a[], int n, int i, double sum)
{
	if (i >= n)
		return sum;
	return tongDQDuoi(a, n, i + 1, sum + a[i]);
}
int main()
{
	const char *s = "DaySo35.txt";
	int n;
	double a[MAX];
	readFile(s, a, &n);
	xuat(a, n);

	printf("so nho nhat trong day (de quy): %.4lf\n", minNumDQ(a, n, a[0]));
	printf("so nho nhat trong day (vong lap): %.4lf\n", minNumVL(a, n));

	printf("tong cac phan tu trong day dung de quy dau: %.4lf\n", tongDQDau(a, n));
	printf("tong cac phan tu trong day dung de quy duoi: %.4lf", tongDQDuoi(a, n, 0, 0.0));
}

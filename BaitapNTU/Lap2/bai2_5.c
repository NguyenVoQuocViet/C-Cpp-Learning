#include <stdio.h>
#include <string.h>

struct HocPhan
{
	char mahp[100];
	char tenhp[100];
	int sotc;
};
typedef struct HocPhan HocPhan;

void nhap(char *s, HocPhan hp[], int *n)
{
	FILE *f = fopen(s, "r");
	if(f != NULL)
	{
		fscanf(f, "%d\n", n);
		if((*n) < 2 || (*n) >= 50)
		{
			printf("so luong khong hop le");
			return;
		}
		int i;
		for(i = 0; i < (*n); i++)
		{
			fgets(hp[i].mahp, 100, f);
			hp[i].mahp[strlen(hp[i].mahp) - 1] = '\0';
			fgets(hp[i].tenhp, 100, f);
			hp[i].tenhp[strlen(hp[i].tenhp) - 1] = '\0';
			fscanf(f, "%d\n", &hp[i].sotc);
		}
		fclose(f);
	}
	else
	{
		printf("NOT OPEN FILE!");
	}
}

void xuat(HocPhan hp[], int n)
{
	printf("so hoc phan: %d\n", n);
	printf("danh sach hoc phan:\n");
	int i;
	for(i = 0; i < n; i++)
	{
		printf("%s\n%s\n%d\n", hp[i].mahp, hp[i].tenhp, hp[i].sotc);
	}
}

int main()
{
	int n;
	HocPhan hp[50];
	char *s = "HocPhan.txt";
	nhap(s, hp, &n);
	xuat(hp, n);
	return 0;
}

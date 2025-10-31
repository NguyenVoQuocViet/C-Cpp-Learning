#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void nhap(char* s)
{
	fgets(s, 100, stdin);
	if(s[strlen(s) - 1] == '\n')
		s[strlen(s) - 1] = '\0';
}

int doDai(char* s)
{
	if(*s == '\0')
		return ;
	return 1 + doDai(s + 1);
}

int demThuong(char* s)
{
	if(*s == '\0')
		return 0;
	if(*s >= 'a' && *s <= 'z')
		return 1 + demThuong(s + 1);
	else
		return demThuong(s + 1);
}

int palin(char* s, int i, int n)
{
	if(i > n)
	{
		return 1;	
	}
	if(s[i] != s[n - i])
		return 0;
	else
		return palin(s, i + 1, n);
	
}

int tongChuSo(char* s)
{
	if(*s == '\0')
		return 0;
	if(*s >= '0' && *s <= '9')
	{
		int n = *s - '0';
		return n + tongChuSo(s + 1);
	}
	else
		return tongChuSo(s + 1);
}
int main()
{
	char* s = (char*)malloc(101);;
	nhap(s);
	int n = doDai(s);
	printf("do dai cua chuoi: %d\n", n);
	
	printf("so ky tu thuong: %d\n", demThuong(s));
	
	if(palin(s, 0, n - 1))
		printf("chuoi doi xung\n");
	else
		printf("chuoi khong doi xung\n");
		
	printf("tong cac chu so trong chuoi: %d", tongChuSo(s));
	free(s);
}

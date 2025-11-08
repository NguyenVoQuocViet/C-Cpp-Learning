#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX 101

void nhap(char* s)
{
    fgets(s, MAX, stdin);
    if (s[strlen(s) - 1] == '\n')
        s[strlen(s) - 1] = '\0';
}

int demChuSo(char* s)
{
    if(*s == '\0')
        return 0;
    if (isdigit(*s))
        return demChuSo(s + 1) + 1;
    return demChuSo(s + 1);
}

int demChuHoa(char* s)
{
    if (*s == '\0')
        return 0;
    if(isupper(*s))
        return demChuHoa(s + 1) + 1;
    return demChuHoa(s + 1);
}

int chuoiTang(char* s)
{
    if(*(s + 1) == '\0')
        return 1;
    if(*s > *(s + 1))
        return 0;
    return chuoiTang(s + 1);
}
int main()
{
    char* s = (char*)malloc(MAX);
    nhap(s);
    printf("so ky tu chu so trong chuoi: %d\n", demChuSo(s));
    printf("so ky tu hoa trong chuoi: %d\n", demChuHoa(s));
    if (chuoiTang(s))
        printf("chuoi co ky tu tang dan");
    else    
        printf("chuoi khong co ky tu tang dan");
    free(s);
    return 0;
}
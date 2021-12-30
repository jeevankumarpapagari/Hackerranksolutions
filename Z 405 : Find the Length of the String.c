#include<stdio.h>
int strlen(char* s)
{
    int len = 0;
    while(*(s++))
        len++;
    return len;
}
int main()
{
	char str[50];
	gets(str);
	printf("%d", strlen(str));
	return 0;
}

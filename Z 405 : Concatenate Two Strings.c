#include<stdio.h>
void strcat(char* s1, char* s2)
{
    while(*s1)
        s1++;
    while(*s2)
        *(s1++) = *(s2++);
    *(s1++) = '\0'; 
}
int main()
{
	char str1[50], str2[50];
	gets(str1);
	gets(str2);
	strcat(str1, str2);
	puts(str1);	
	return 0;
}

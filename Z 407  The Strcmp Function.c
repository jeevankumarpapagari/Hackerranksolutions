#include<stdio.h>
int strcmp(char* s1, char* s2)
{
    /*
        s1-> 0:s 1:t 2:u 3:p 4:e 5:f 6:y 7:\0
        s2-> 0:w 1:i 2:n 3:g 4:a 5:r 6:d 7:i 8:u 9:m 10: 11:l 12:e 13:v 14:i 15:o 16:s 17:a 18:\0
    */
	while(*s1)
    {
        if(*s1 != *s2)
            return *s1 - *s2;
        s1++;
        s2++;
    }
    return *s1-*s2;
}

int main()
{
	char str1[50], str2[50];
	gets(str1);
	gets(str2);
    //printf("ASCII Code of NULL: %d %d\n",'\0','K');
	printf("%d", strcmp(str1, str2));	
	return 0;
}

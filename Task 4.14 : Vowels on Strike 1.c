#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    char str[1000], ch;
    gets(str);
    
    int i = -1;
    
    while((ch=str[++i])!='\0')
        (ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'||ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U') ? printf("") : printf("%c",ch);
    return 0;
}

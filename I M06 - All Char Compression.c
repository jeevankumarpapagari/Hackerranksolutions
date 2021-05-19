#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    char str[1000];
    scanf("%s",str);
    int i;
    for(i=1;str[i];i++)
        if(str[i] != str[i-1])
            printf("%c",str[i-1]);
    printf("%c",str[i-1]);
    return 0;
}

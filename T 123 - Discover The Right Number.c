#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    char str[100];
    scanf("%s",str);
    int result = 0, i = 0;
    while(str[i])
    {
        result = (result*26) + (str[i]-'A'+1);
        i++;
    }
    printf("%d",result);
    return 0;
}

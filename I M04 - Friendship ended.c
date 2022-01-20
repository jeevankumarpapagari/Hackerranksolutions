#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    char str[1000], msg[] = "Goodbye";
    scanf("%s",str);
    
    int strLen = strlen(str), msgLen = strlen(msg), i, j;
    
    for(i=0,j=0;i<strLen && j<msgLen;i++)
        if(str[i] == msg[j])
            j++;
    
    j==msgLen ? printf("Yes") : printf("No");
    
    return 0;
}

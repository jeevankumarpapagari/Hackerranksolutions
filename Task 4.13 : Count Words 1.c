#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    char str[1000];
    scanf("%[^\n]s",str);
    
    int i = -1, wordCount = 0;
    
    while(str[++i])
        if(str[i]==' ')
            wordCount++;
    
    printf("%d",wordCount+1);
    return 0;
}

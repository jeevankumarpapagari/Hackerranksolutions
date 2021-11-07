#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    char actualMessage[] = "hello", typedMessage[101];
    scanf("%s",typedMessage);
    
    int i = 0, j = 0, lengthOfAM = strlen(actualMessage), lengthOfTM = strlen(typedMessage);
    
    while(i<lengthOfAM && j<lengthOfTM)
        if(typedMessage[j++] == actualMessage[i])
            i++;
    
    i==lengthOfAM ? printf("YES") : printf("NO");
    
    return 0;
}

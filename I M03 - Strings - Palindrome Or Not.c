#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    char str[100];
    scanf("%[^\n]s",str);
    
    int i = 0, j = strlen(str) - 1;
    while(i < j)
    {
        /*
            0:b 1:a 2:n 3:a 4:n 5:a 6:\0
            b <--> a
            
            0:k 1:a 2:y 3:a 4:k 5:\0
            i:0 -> k <--> k -> j:4 [0 < 4]
            i:1 -> a <--> a -> j:3 [1 < 3]
        */
        if(str[i] != str[j])
        {
            printf("no");
            return 0;
        }
        i++;j--;
    }
    printf("yes");
    return 0;
}

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    char str[1000];
    gets(str);
    int N = (int)ceil(sqrt(strlen(str)));
    //char result[N][N];
    int i,j,index = 0;
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            if(index < strlen(str))
                printf("%c",str[index++]);
            else
                printf("?");
        }
        printf("\n");
    }
    return 0;
}

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int compare(const void *x,const void *y)
{
    return *(char*)x - *(char*)y;
}

int main()
{
    int n;
    scanf("%d",&n);
    
    char result[n];
    int j = 0;
    
    for(int i=1;i<=n;i++)
    {
        char word[10003];
        scanf("%s",word);
        
        qsort(word,strlen(word),sizeof(char),compare);
        
        result[j++] = word[0];
    }
    result[j] = '\0';
    qsort(result,strlen(result),sizeof(char),compare);
    printf("%s",result);
    
    return 0;
}

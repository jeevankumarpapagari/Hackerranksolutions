#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int compare(const void *x,const void *y)
{
    return *(int*)y - *(int*)x;
}

int main() 
{
    int n;
    scanf("%d",&n);
    
    int cupCakeCalories[n], i;
    for(i=0;i<n;i++)
        scanf("%d",&cupCakeCalories[i]);
    
    qsort(cupCakeCalories,n,sizeof(int),compare);
    
    long result = 0;
    int j = 0;
    for(i=0;i<n;i++)
        result += (cupCakeCalories[i] * pow(2,j++));
    
    printf("%ld",result);
    
    return 0;
}

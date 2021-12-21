#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    int n1;
    scanf("%d",&n1);
    int class1[n1], i;
    for(i=0;i<n1;i++)
        scanf("%d",&class1[i]);
    
    int n2;
    scanf("%d",&n2);
    int class2[n2], j;
    for(j=0;j<n2;j++)
        scanf("%d",&class2[j]);
    
    int finalList[n1+n2], k = 0;
    i = 0; j = 0;
    
    while(i<n1 && j<n2)
        finalList[k++] = class1[i] <= class2[j] ? class1[i++] : class2[j++];
    
    while(i < n1)
        finalList[k++] = class1[i++];
    
    while(j < n2)
        finalList[k++] = class2[j++];
    
    for(i=0;i<n1+n2;i++)
        printf("%d ",finalList[i]);
        
    return 0;
}

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    int numberOfElements, borderValue;
    scanf("%d%d",&numberOfElements,&borderValue);
    int arr[numberOfElements], i;
    for(i=0;i<numberOfElements;i++) scanf("%d",&arr[i]);
    
    for(i=borderValue-1; i<numberOfElements; i+=borderValue)
        printf("%d ",arr[i]);
    return 0;
}

/*

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    int numberOfElements, borderValue;
    scanf("%d%d",&numberOfElements,&borderValue);
    int rows = numberOfElements / borderValue;
    int cols = borderValue;
    int arr[rows][cols],i,j;
    for(i=0;i<rows;i++)
        for(j=0;j<cols;j++)
            scanf("%d",&arr[i][j]);
    for(i=0;i<rows;i++)
        printf("%d ",arr[i][cols-1]);
    return 0;
}
*/
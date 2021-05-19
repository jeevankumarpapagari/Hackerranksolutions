#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    int totalNumberOfElements;
    scanf("%d",&totalNumberOfElements);
    
    int arrElements[totalNumberOfElements],index;
    for(index=0;index<totalNumberOfElements;index++)    scanf("%d",&arrElements[index]);
    
    index = 1;
    while(index<totalNumberOfElements && arrElements[index]>arrElements[index-1])       index++;
    while(index<totalNumberOfElements && arrElements[index] == arrElements[index-1])    index++;
    while(index<totalNumberOfElements && arrElements[index] < arrElements[index-1])     index++;
    
    if(index== totalNumberOfElements)   printf("yes");
    else                                printf("no");
    return 0;
}

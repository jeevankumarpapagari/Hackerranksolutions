#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int LeaderSum(int array_size, int* array) 
{
    int i, sum = 0;
    int maxIndex = 0, maxValue = *(array+0);
    for(i=0;i<array_size;i++)
    {
        if(maxValue < *(array+i))
        {
            maxValue = *(array+i);
            maxIndex = i;
        }
    }
    
    //printf("%d %d\n",maxValue,maxIndex);
    
    for(i=maxIndex;i<array_size;i++)
        sum += *(array+i);
    return sum;
}

int main() {
    int n, array_i; 
    scanf("%i", &n);
    int *array = malloc(sizeof(int) * n);
    for (array_i = 0; array_i < n; array_i++) {
    	scanf("%i",&array[array_i]);
    }
    int result = LeaderSum(n, array);
    printf("%d\n", result);
    return 0;
}

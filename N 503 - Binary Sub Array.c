#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int MaxBinaryStringLen(int array_size, int* array) 
{
    int result = 0, count = 0,i;
    for(i=0;i<array_size;i++)
    {
        if(*(array+i) == 1)
            count++;
        else
        {
            result = result > count ? result : count;
            count = 0;
        }
    }
    return result>count ? result : count;
    
}

int main() {
    int n; 
    scanf("%i", &n);
    int *array = malloc(sizeof(int) * n), array_i;
    for (array_i = 0; array_i < n; array_i++) 
    {
    	scanf("%i",&array[array_i]);
    }
    int result = MaxBinaryStringLen(n, array);
    printf("%d\n", result);
    return 0;
}

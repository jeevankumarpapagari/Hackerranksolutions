#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int cmp(int *a,int *b)
{
    return *a - *b;
}


int main() 
{
    /*
        => Read elements into an array ==> 4 2 1 3 8
        => Sort all the elements in ascending order ==> 0:1 1:2 2:3 3:4 4:8
        => copy all of the even position elements into one array ==> 0:1 2:3 4:8 -> EvenIndex array
        => copy all of the odd position elements into another array  => 1:2 3:4 -> OddIndex array
        => Print data:
            -> First print evenindex array element, oddIndex array element [Note: if n is even number]
                    2 1 4 3
            -> print last element of evenIndex array if n is odd value
    */
    int n,i;
    scanf("%d",&n);
    //Read elements into an array
    int arr[n];
    for(i=0;i<n;i++)    scanf("%d",&arr[i]);
    
    //Sort all the elements in ascending order
    qsort(arr,n,sizeof(arr[0]),cmp);
    
    int evenArray[n], oddArray[n],k,l;
    for(i=0,k=0,l=0;i<n;i++)
    {
        if(i%2==0)  evenArray[k++] = arr[i];
        else        oddArray[l++] = arr[i];
    }
    
    for(i=0;i<l;i++)
        printf("%d %d ",oddArray[i],evenArray[i]);
    if(n%2)     printf("%d",evenArray[k-1]);
    return 0;
}

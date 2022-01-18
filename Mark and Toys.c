#include<stdio.h>
#include<stdlib.h>

int compare(const void *x,const void *y)
{
    return *(int*)x - *(int*)y; 
}

int main()
{
    //Reading total number of toys and amount: O(1)
    int numberOfToys, amount;
    printf("Enter total number of toys and Amount value: ");
    scanf("%d %d",&numberOfToys,&amount);

    //Reading pricelist into an array: O(N)
    int priceList[numberOfToys], i;
    printf("\nEnter price list: ");
    for(i=0;i<numberOfToys;i++)
        scanf("%d",&priceList[i]);
    
    //Sorting price list into ascending order: O(N logN)
    qsort(priceList,numberOfToys,sizeof(int),compare);

    //To printing pricelist after sorting: O(N) 
    printf("\nPrinting price list after sorting: ");
    for(i=0;i<numberOfToys;i++)
        printf("%d ",priceList[i]);
    
    //Calculating result value: O(N)
    i = 0;
    int result = 0, sum = 0;
    while(sum+priceList[i] <= amount)
    {
        result++;
        sum = sum + priceList[i++];
    }

    //Printing output value: O(1)
    printf("\nTotal number of Toys can Mark Buy: %d",result);

    /*
        FInal time complexity: O(N logN)
            -> To sort: O(N logN) [Maximum]
            -> To calculate: O(N) [Minimum]
    */
    return 0;
}

#include<stdio.h>
int main()
{
    //O(1)
    int numberOfObjects;
    printf("Enter total number of objects: ");
    scanf("%d",&numberOfObjects);

    //O(n)
    int i,j;
    float profits[numberOfObjects], weights[numberOfObjects], profitByWeight[numberOfObjects];
    float temp;
    for(i=0;i<numberOfObjects;i++)
    {
        scanf("%f %f",&profits[i],&weights[i]);
        profitByWeight[i] = profits[i] / weights[i];
    }

    //O(n^2)
    for(i=0;i<numberOfObjects-1;i++)
    {
        for(j=i+1;j<numberOfObjects;j++)
        {
            if(profitByWeight[i] < profitByWeight[j])
            {
                temp = profitByWeight[i];
                profitByWeight[i] = profitByWeight[j];
                profitByWeight[j] = temp;

                temp = profits[i];
                profits[i] = profits[j];
                profits[j] = temp;

                temp = weights[i];
                weights[i] = weights[j];
                weights[j] = temp;
            }
        }
    }

    //O(1)
    float knapsackCapacity, finalProfit = 0;
    printf("\nEnter knapsack capacity: ");
    scanf("%f",&knapsackCapacity);

    //O(n)
    i = 0;
    while(i < numberOfObjects)
    {
        if(weights[i] > knapsackCapacity)
            break;
        finalProfit = finalProfit + profits[i];
        knapsackCapacity = knapsackCapacity - weights[i];
        i++;
    }

    //O(1)
    if(i < numberOfObjects)
        finalProfit = finalProfit + (knapsackCapacity/weights[i])*profits[i];

    //O(1)
    printf("\nMaximum profit is: %f",finalProfit);
    return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int compare(const void *x,const void *y)
{
    return *(int*)x - *(int*)y;
}

int main()
{
    int numberOfCakes;
    printf("Enter total number of cupcakes: ");
    scanf("%d",&numberOfCakes);

    int calorieOfCups[numberOfCakes], i;
    printf("\nEnter each cup calorie information: ");
    for(i=0;i<numberOfCakes;i++)
        scanf("%d",&calorieOfCups[i]);
    
    printf("\nBefore sorting cupcake calorie information: ");
    for(i=0;i<numberOfCakes;i++)
        printf("%d ",calorieOfCups[i]);
    
    qsort(calorieOfCups,numberOfCakes,sizeof(int),compare);

    long minMilesToWalk = 0;
    for(i=numberOfCakes-1;i>=0;i--)
        minMilesToWalk += pow(2,numberOfCakes-1-i) * calorieOfCups[i];

    printf("\nAfter sorting cupcake calorie information: ");
    for(i=0;i<numberOfCakes;i++)
        printf("%d ",calorieOfCups[i]);
    
    printf("\n\nMinimum miles to walk by Mr.Mark is: %ld",minMilesToWalk);
    return 0;
    /*
        Time Complexity: [O(N LogN)]
            -> Sorting the cupcakes calorie information: O(N LogN) [Maximum]
            -> TO calculate result: O(N) [Minimum]
    */
}

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    int power,noOfOpponants,totalNumberOfDays = 0,tempPower;
    scanf("%d",&power); //Reading pokeman power
    scanf("%d",&noOfOpponants); //Reading total number of opponants
    int opponantPowers[noOfOpponants],i; //Declaring an array to store opponant power values
    for(i=0;i<noOfOpponants;i++)
        scanf("%d",&opponantPowers[i]); //Reading opponant power values
    //Process to find to win the battle
    tempPower = power;
    for(i=0;i<noOfOpponants;i++)
    {
        if(power <= opponantPowers[i])
        {
            printf("-1");
            return 0;
        }
        if(tempPower > opponantPowers[i])
            tempPower = tempPower - opponantPowers[i];
        else
        {
            totalNumberOfDays++; //Day value got increments
            tempPower = power; //Reacharging
            tempPower = tempPower - opponantPowers[i];//Battle begin next day
            //Above statement can be replaced with i--
        }
    }
    printf("%d",totalNumberOfDays+1);
    return 0;
}

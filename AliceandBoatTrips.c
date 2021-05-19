#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    /*
        The first line contains three space-separated integers describing the respective values of 
        n (number of trips), 
        c (boat capacity), and 
        m (total number of boats). 
        The second line contains n space-separated integers describing the values of p0, p1, p2... pn-1
        5 2 2
        0:1 1:2 2:2 3:4 4:3
    */
    int numberOfTrips,eachBoatCapacity,totalNumberOfBoats;
    scanf("%d%d%d",&numberOfTrips,&eachBoatCapacity,&totalNumberOfBoats);
    int passengerGroup[numberOfTrips],i,check = 1;
    for(i=0;i<numberOfTrips;i++)
    {
        scanf("%d",&passengerGroup[i]);
        if(passengerGroup[i] > eachBoatCapacity * totalNumberOfBoats)
            check = 0;
    }
    if(check == 1)  printf("Yes");
    else            printf("No");
    return 0;
}

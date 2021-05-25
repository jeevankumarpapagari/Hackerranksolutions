#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

/*
    n = 5
    1 => 2  => 2        => 2
    2 => 3  => 6        => 4 (Buying on day1)
    3 => 1  => 3        => 3
    4 => 2  => 8        => 4 (Buying on day3)
    5 => 4  => 20       => 5 (Buying on day3)
    Total Val: 39$        18$
    
    15 Litre petrol => Bike tank capacity => 17Litrs
    1 => 80 =>  80      =>  80 => total = 3
    2 => 82 => 164      => 160 (On day1 you fill extra 2 litres)
    3 => 78 => 234      => 234 => total = 7
    4 => 80 => 320      => 312 (On day3 you fill extra 4 litres)
    5 => 75 => 375      => 375 => total = 5
       Total: 1173        1161    
*/
int main() 
{
    int n;
    scanf("%d",&n);
    int day[n],paneerCost[n],i;
    for(i=0;i<n;i++)
        scanf("%d%d",&day[i],&paneerCost[i]);
    for(i=0;i<n-1;i++)
    {
        if(paneerCost[i] < paneerCost[i+1])
            paneerCost[i+1] = paneerCost[i];
    }
    int result = 0;
    for(i=0;i<n;i++)
        result += day[i] * paneerCost[i];
    printf("%d",result);
    return 0;
}

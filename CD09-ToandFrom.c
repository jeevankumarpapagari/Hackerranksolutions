#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    /*
        N Next N lines, contain a tuple containing 4 values delimited by space F B T D, where 
        1. F denotes forward displacement in meters 
        2. B denotes backward displacement in meters 
        3. T denotes time taken to cover 1 meter 
        4. D denotes distance from Car's starting position and the wall in backward direction
        F B T D
        3 7 5 20
    */
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int f,b,t,d,td=0;
        scanf("%d%d%d%d",&f,&b,&t,&d);
        while(b<d)//1. 7<20(T) 2. 7<16 3. 7<12 4. 7<8 5. 7<4(False)
        {
            td = td + b + f;//1. 0+7+3 = 10 => 10+7+3 = 20 => 20+7+3 = 30 => 30+7+3 = 40
            d = d - (b-f);//1. 20-(7-3)=20-4=16 => 16-4 = 12 => 12-4 = 8 => 8-4 = 4
        }
        td = td + d;//40+4=>44
        printf("%d\n",td*t);//44*5=>220
    }
    return 0;
}

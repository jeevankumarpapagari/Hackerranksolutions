#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() 
{
    int n,m,g11,g12,g21,g22;
    scanf("%d %d %d %d %d %d",&n,&m,&g11,&g12,&g21,&g22);
    
    int i, j, min1, min2, result = 0;
    
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            min1 = (i<g11 ? g11-i : i-g11) + (j<g12 ? g12-j : j-g12);
            min2 = (i<g21 ? g21-i : i-g21) + (j<g22 ? g22-j : j-g22);
            result = min1 == min2 ? result+1 : result;
        }
    }
    printf("%d",result);
    return 0;
}

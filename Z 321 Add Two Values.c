#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    double f1, f2;
    scanf("%lf %lf",&f1,&f2);
    
    (long)(f1+f2) < (f1+f2) ? printf("%.2lf",f1+f2) : printf("%ld",(long)(f1+f2));
    
    return 0;
}

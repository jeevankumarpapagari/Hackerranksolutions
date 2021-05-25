#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int previousRating, presentRating;
    scanf("%d%d",&previousRating,&presentRating);
    if(previousRating == presentRating)     printf("Did not participate");
    else if(previousRating < presentRating) printf("Performed well");
    else                                    printf("Did not perform well");
    return 0;
}

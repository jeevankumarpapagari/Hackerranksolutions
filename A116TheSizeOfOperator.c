#include <stdio.h>
int main()
{
	printf("%ld ",sizeof(char));
    printf("%ld ",sizeof(int));
    printf("%ld ",sizeof(float));
    printf("%ld ",sizeof(long long));
    printf("%ld",sizeof(double));
    
    //printf("%ld %ld %ld %ld %ld",sizeof(char),sizeof(int),sizeof(float),sizeof(long long),sizeof(double))
	return 0;
}

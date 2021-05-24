#include <stdio.h>

int main()
{
	int number, is_prime=1, i;
	scanf("%d", &number);
	//your code here
	//hint : loop through all the numbers less than number and see if any of them divides it
    if(number <= 1) is_prime = 0;
    else
    {
        for(i=2;i<=number/2;i++)
        {
            if(number % 2 == 0)
            {
                is_prime = 0;
                break;
            }
        }
    }
    	
	if (is_prime == 1) printf("yes");
	if (is_prime == 0) printf("no");
	return 0;
}

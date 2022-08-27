#include<stdio.h>
#define MAX 100

int top = -1;
char stack[MAX];

void push(char ch)
{
    stack[++top] = ch;
}

int main()
{
    char str[100];
    printf("Enter input bracket srting: ");
    scanf("%s",str);

    int i = -1;
    while(str[++i])
    {
        char ch = str[i];
        if(ch == '(' || ch == '[' || ch == '{')
            push(str[i]);
        else if((ch==')'&&stack[top]=='(') || (ch==']'&&stack[top]=='[') || (ch=='}'&&stack[top]=='{'))
            top--;
        else
        {
            printf("\nNO");
            return 0;
        }
    }
    str[i]!='\0' ? printf("\nNO") : printf("\nYES");
    return 0;
}

#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "math.h"

int stackArr[100005], top = -1; 
void push(int x)
{
    stackArr[++top] = x;
}
int peek()
{
    return stackArr[top];
}
void pop()
{
    top--;
}
int empty() 
{
    return (top == -1) ? 1 : 0;
}

int main()
{
    int n, i, j;
    top = -1;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        int t, x;
        scanf("%d", &t);
        if (t == 1) {
            scanf("%d", &x);
            push(x);
        }
        else if (t == 2) {
            if (empty()) {
                printf("Invalid\n");
            }
            else {
                pop();
            }
        }
        else if (t == 3){
            if (empty()) {
                printf("Invalid\n");
                continue;
            }
            for (j = top; j >= 0; j--) {
                printf("%d ", stackArr[j]);
            }printf("\n");
        }
        else {
            if (empty()) {
                printf("Invalid\n");
                continue;
            }
            printf("%d\n", peek());
        }
    }
    return 0;
}

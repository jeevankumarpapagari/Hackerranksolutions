#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "math.h"

struct stackNode{
    int val;
    struct stackNode* next;
};
typedef struct stackNode stackNode;
stackNode* stackHead; //- Head Pointer for stack LinkedList

void push(int x) //- Insert an element onto the top of the stack
{
    stackNode *newNode = (stackNode*)malloc(sizeof(stackNode));
    newNode->val = x;
    newNode->next = stackHead;
    stackHead = newNode;
}

int peek()// - Returns the topmost element on the stack
{
    return stackHead->val;
}

void pop() //- Removes an element from the top of the stack
{
    stackNode *temp = stackHead;
    stackHead = stackHead->next;
    free(temp);
}

int empty() //- Returns 1 if the stack is empty and 0 otherwise
{
    return stackHead==NULL ? 1 : 0;
}

//TAIL

int main()
{
    int n, i;
    stackHead = NULL;
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
            stackNode* j = stackHead;
            while (j) {
                printf("%d ", j->val);
                j = j->next;
            }
            printf("\n");
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
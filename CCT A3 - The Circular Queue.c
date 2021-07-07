//HEAD

#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "math.h"

struct queueNode{
    int data;
    struct queueNode* next;
};
typedef struct queueNode queueNode;
queueNode* head = NULL;

queueNode* newNode(int val)
{
    queueNode* t = (queueNode*) malloc(sizeof(queueNode));
    t->data = val, t->next = NULL;
    return t;
}

//BODY

void push(int val)
{
    queueNode *newOne = newNode(val);
    if(head == NULL)
    {
        newOne->next = newOne;
        head = newOne;
    }
    else
    {
        newOne->next = head->next;
        head->next = newOne;
        head = newOne;
    }
}
void pop()
{
    if(head->next == head || head == NULL)
    {
        queueNode *temp = head;
        head = NULL;
        free(temp);
    }
    else
    {
        queueNode *temp = head->next;
        head->next = head->next->next;
        temp->next = NULL;
        free(temp);
    }
}
int top()
{
    return head->next->data;
}
int empty()
{
    return head == NULL ? 1 : 0;
}

// TAIL

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        char s[50];
        int x;
        scanf(" %s", s);
        if (s[0] == 't')
        {
            if (empty()) printf("Invalid\n");
            else                
                printf("%d\n", top());
        }
        else if (s[0] == 'p' && s[1] == 'o')
        {
            if (empty()) printf("Invalid\n");
            else    pop();
        }
        else
        {
            scanf(" %d", &x);
            push(x);
        }
    }
    return 0;
}
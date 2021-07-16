#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
typedef struct LinkedListNode LinkedListNode;

struct LinkedListNode {
    char val;
    LinkedListNode *next;
};

LinkedListNode* _insert_node_into_singlylinkedlist(LinkedListNode *head, LinkedListNode *tail, char val) {
    if(head == NULL) {
        head = (LinkedListNode *) (malloc(sizeof(LinkedListNode)));
        head->val = val;
        head->next = NULL;
        tail = head;
    }
    else {
        LinkedListNode *node = (LinkedListNode *) (malloc(sizeof(LinkedListNode)));
        node->val = val;
        node->next = NULL;
        tail->next = node;
        tail = tail->next;
    }
    return tail;
}


/*
 * Complete the function below.
 */
/*
For your reference:
LinkedListNode {
    char val;
    LinkedListNode *next;
};
*/
void reverse(LinkedListNode **headRef)
{
    LinkedListNode *previous = NULL, *current = *headRef, *next = NULL;
    while(current)
    {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    *headRef = previous;
}

bool compareLists(LinkedListNode *h1, LinkedListNode *h2)
{
    LinkedListNode *t1 = h1;
    LinkedListNode *t2 = h2;
    while(t1 && t2)
    {
        if(t1->val != t2->val)
            return false;
        t1 = t1->next;
        t2 = t2->next;
    }
    return t1==NULL && t2==NULL ? true : false;
}

bool isPalindrome(LinkedListNode* head) 
{
    LinkedListNode *slowPtr = head, *fastPtr = head, *previousSlowPtr = head, *secondHalf = NULL, *midNode = NULL;
    int result = true;
    if(head && head->next)
    {
        while(fastPtr && fastPtr->next)
        {
            fastPtr = fastPtr->next->next;
            previousSlowPtr = slowPtr;
            slowPtr = slowPtr->next;
        }
        if(fastPtr)
        {
            midNode = slowPtr;
            slowPtr = slowPtr->next;
        }
        secondHalf = slowPtr;
        previousSlowPtr->next = NULL;
        reverse(&secondHalf);
        result = compareLists(head,secondHalf);
    }
    return result;
}

int main()
{
    FILE *f = stdout;
    char *output_path = getenv("OUTPUT_PATH");
    if (output_path) {
        f = fopen(output_path, "w");
    }

    bool res;
    int head_size = 0;

    LinkedListNode* head = NULL;
    LinkedListNode* head_tail = NULL;

    scanf("%d", &head_size);
 	char s[10005];
  	scanf(" %s", s);
    for(int i = 0; i < head_size; i++) {
        char head_item = s[i];
        head_tail = _insert_node_into_singlylinkedlist(head, head_tail, head_item);

        if(i == 0) {
            head = head_tail;
        }
    }


    res = isPalindrome(head);
    fprintf(f, "%d\n", res);

    fclose(f);
    return 0;
}

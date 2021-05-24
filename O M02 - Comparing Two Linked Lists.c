#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
typedef struct LinkedListNode LinkedListNode;

struct LinkedListNode {
    int val;
    LinkedListNode *next;
};

LinkedListNode* _insert_node_into_singlylinkedlist(LinkedListNode *head, LinkedListNode *tail, int val) 
{
    if(head == NULL) 
    {
        head = (LinkedListNode *) (malloc(sizeof(LinkedListNode)));
        head->val = val;
        head->next = NULL;
        tail = head;
    }
    else 
    {
        LinkedListNode *node = (LinkedListNode *) (malloc(sizeof(LinkedListNode)));
        node->val = val;
        node->next = NULL;
        tail->next = node;
        tail = tail->next;
    }
    return tail;
}

int compare(LinkedListNode* headA, LinkedListNode* headB) 
{
    /*
        List1 => 1->2->3->4->NULL
        List2 => 1->2->NULL
        
        List1 => 1->2->NULL
        List2 => 1->3->NULL
        
        List1 => 1->2->NULL
        List2 => 1->2->NULL
    */
    while(headA && headB)//headA!=NULL && headB!=NULL
    {
        if(headA->val != headB->val)
            return 0;
        headA = headA->next;
        headB = headB->next;
    }
    if(headA==NULL && headB==NULL)  return 1;
    else                            return 0;
}

int main()
{
    FILE *f = stdout;
    char *output_path = getenv("OUTPUT_PATH");
    if (output_path) {
        f = fopen(output_path, "w");
    }

    int res;
    int headA_size = 0;

    LinkedListNode* headA = NULL;
    LinkedListNode* headA_tail = NULL;

    scanf("%d\n", &headA_size);
    int i;
    for(i = 0; i < headA_size; i++) 
    {
        int headA_item;
        scanf("%d", &headA_item);
        headA_tail = _insert_node_into_singlylinkedlist(headA, headA_tail, headA_item);

        if(i == 0) {
            headA = headA_tail;
        }
    }

    int headB_size = 0;

    LinkedListNode* headB = NULL;
    LinkedListNode* headB_tail = NULL;

    scanf("%d\n", &headB_size);
    int i;
    for(i = 0; i < headB_size; i++) {
        int headB_item;
        scanf("%d", &headB_item);
        headB_tail = _insert_node_into_singlylinkedlist(headB, headB_tail, headB_item);

        if(i == 0) {
            headB = headB_tail;
        }
    }
    res = compare(headA, headB);
    fprintf(f, "%d\n", res);

    fclose(f);
    return 0;
}

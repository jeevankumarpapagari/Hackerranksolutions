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

LinkedListNode* _insert_node_into_singlylinkedlist(LinkedListNode *head, LinkedListNode *tail, int val) {
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
    int val;
    LinkedListNode *next;
};
*/

LinkedListNode* newNode(int val)
{
    LinkedListNode *newOne = (LinkedListNode*) malloc(sizeof(LinkedListNode));
    newOne->val = val;
    newOne->next = NULL;
    return newOne;
}
void reverse(LinkedListNode **headRef)
{
    LinkedListNode *previous = NULL,*current = *headRef, *next = NULL;
    while(current)
    {
        next = current->next;
        current->next = previous;
        previous = current;
        current= next;
    }
    *headRef = previous;
}

LinkedListNode* addLists(LinkedListNode* list1, LinkedListNode* list2) 
{
    reverse(&list1);
    reverse(&list2);
    
    LinkedListNode *previous = NULL, *node = NULL, *head = NULL;
    int c = 0, C = 0;
    while(list1 || list2 || c > 0)
    {
        if(list1)
            C += list1->val;
        if(list2)
            C += list2->val;
        
        C += c;
        c = (C/10) % 10;
        C = C%10;
        
        node = newNode(C);
        
        if(previous == NULL)
        {
            head = node;
            previous = node;
        }
        else
        {
            previous->next = node;
            previous = node;
        }
        
        if(list1)
            list1 = list1->next;
        if(list2)
            list2 = list2->next;
        C = 0;
    }
    reverse(&head);
    return head;
}

int main()
{
    FILE *f = stdout;
    char *output_path = getenv("OUTPUT_PATH");
    if (output_path) {
        f = fopen(output_path, "w");
    }

    LinkedListNode* res;
    int list1_size = 0;

    LinkedListNode* list1 = NULL;
    LinkedListNode* list1_tail = NULL;

    scanf("%d\n", &list1_size);
    for(int i = 0; i < list1_size; i++) {
        int list1_item;
        scanf("%d", &list1_item);
        list1_tail = _insert_node_into_singlylinkedlist(list1, list1_tail, list1_item);

        if(i == 0) {
            list1 = list1_tail;
        }
    }


    int list2_size = 0;

    LinkedListNode* list2 = NULL;
    LinkedListNode* list2_tail = NULL;

    scanf("%d\n", &list2_size);
    for(int i = 0; i < list2_size; i++) {
        int list2_item;
        scanf("%d", &list2_item);
        list2_tail = _insert_node_into_singlylinkedlist(list2, list2_tail, list2_item);

        if(i == 0) {
            list2 = list2_tail;
        }
    }


    res = addLists(list1, list2);
    while (res != NULL) {
        fprintf(f, "%d", res->val);

        res = res->next;
    }

    fclose(f);
    return 0;
}

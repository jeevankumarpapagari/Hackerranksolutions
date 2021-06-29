//-------------------- head of the code ------------------------

#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#define in(x) scanf(" %d", &x);
#define LinkedListNode LinkedListNode
typedef struct LinkedListNode LinkedListNode;
struct LinkedListNode {
	int val;
	struct LinkedListNode* next;
	struct LinkedListNode* prev;
};


//-------------------- body of the code ------------------------


LinkedListNode* insertAtBeginning(LinkedListNode* head, int val) 
{
    LinkedListNode *newNode = (LinkedListNode*)malloc(sizeof(LinkedListNode));
    newNode->val = val;
    newNode->prev = NULL;
    
    if(head == NULL)
    {
        newNode->next = NULL;
        head = newNode;
    }
    else
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    return head;
}
LinkedListNode* insertAtEnd(LinkedListNode* head, int val) 
{
    LinkedListNode *newNode = (LinkedListNode*)malloc(sizeof(LinkedListNode));
    newNode->val = val;
    newNode->next = NULL;
    
    if(head == NULL)
    {
        newNode->prev = NULL;
        head = newNode;
    }
    else
    {
        LinkedListNode *ptr = head;
        while(ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = newNode;
        newNode->prev = ptr;
    }
    return head;
}
LinkedListNode* insertAtPosition(LinkedListNode* head, int val, int pos) 
{
    if(pos == 1)    return insertAtBeginning(head,val);
    else
    {
        LinkedListNode *newNode = (LinkedListNode*)malloc(sizeof(LinkedListNode));
        newNode->val = val;
        
        LinkedListNode *ptr = head;
        int i;
        for(i=1;i<=pos-2;i++)
        {
            ptr = ptr->next;
            if(ptr == NULL)
                return head;
        }
        LinkedListNode *temp = ptr->next;
        ptr->next = newNode;
        newNode->next = temp;
        if(temp != NULL)
            temp->prev = newNode;
        newNode->prev = ptr;
    }
    return head;
}


//-------------------- tail of the code ------------------------


int rng(int lim) {
	if (lim == 0) return 0;
	return rand()%lim;
}
int a[1005], sz = 0;
void insertt(int val, int pos) {
	if (pos < 0) return;
	if (pos > sz + 1) return;
	sz += 1;
	for (int i = sz; i > pos; i--)
		a[i] = a[i - 1];
	a[pos] = val;
}
void erasee(int pos) {
	if (pos > sz) return;
	if (pos < 1) return;
	sz--;
	for (int i = pos; i <= sz; i++)
		a[i] = a[i + 1];
}
int check(LinkedListNode* head) {
	if (head == NULL && sz == 0) return 1;
	if (head == NULL || sz == 0) return 0;
	LinkedListNode* node = head;
	for (int i = 1; i <= sz; i++) {
		if (node == NULL) return 0;
		if (node->val != a[i]) return 0;
		node = node->next;
	}	
	if (node != NULL) return 0;

	node = head;
	while (node->next)
		node = node->next;

	for (int i = sz; i >= 1; i--) {
		if (node == NULL) return 0;
		if (node->val != a[i]) return 0;
		node = node->prev;
	}
	if (node != NULL) return 0;
	return 1;
}
int main() {
	srand(time(NULL));
	int t, n; in(t); in(n);
	while (t--) {
		LinkedListNode* head = NULL;
		sz = 0;
		for (int i = 0; i < n; i++) {
			int type = rng(3);
			if (type == 0) {
				int val = rng(1000);
				head = insertAtBeginning(head, val);
				insertt(val, 1);
				if (!check(head)) {
					printf("incorrect insertAtBeginning");
					return 0;
				}
			}

			if (type == 1) {
				int val = rng(1000);
				head = insertAtEnd(head, val);
				insertt(val, sz + 1);
				if (!check(head)) {
					printf("incorrect insertAtEnd");
					return 0;
				}
			}

			if (type == 2) {
				int val = rng(1000);
				int pos = rng(sz + 1) + 1;
				head = insertAtPosition(head, val, pos);
				insertt(val, pos);
				if (!check(head)) {
					printf("incorrect insertAtPosition");
					return 0;
				}
			}
		}
	}
	printf("correct");
}
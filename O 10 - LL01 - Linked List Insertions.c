//-------------------- head of the code ------------------------


#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#define in(x) scanf(" %d", &x);
#define LLN LinkedListNode
typedef struct LinkedListNode LinkedListNode;
struct LinkedListNode {
	int val;
	struct LinkedListNode* next;
};

//-------------------- body of the code ------------------------


LinkedListNode* insertAtBeginning(LinkedListNode* head, int val) 
{
    LinkedListNode *newNode = (LinkedListNode*)malloc(sizeof(LinkedListNode));
    newNode->val = val;
    if(head == NULL)    newNode->next = NULL;
    else                newNode->next = head;
    return newNode;
}

LinkedListNode* insertAtEnd(LinkedListNode* head, int val) 
{
    LinkedListNode *newNode = (LinkedListNode*)malloc(sizeof(LinkedListNode));
    newNode->val = val;
    //NUll
    if(head == NULL)
    {
        newNode->next = NULL;
        head = newNode;
    }
    //1->2->3->4->NULL
    else
    {
        LinkedListNode *ptr = head;
        while(ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = newNode;
        newNode->next = NULL;
    }
    return head;
}

LinkedListNode* insertAtPosition(LinkedListNode* head, int val, int pos) 
{
    LinkedListNode *newNode = (LinkedListNode*)malloc(sizeof(LinkedListNode));
    newNode->val = val;
    if(pos==1)      return insertAtBeginning(head,val);
    else
    {
        LinkedListNode *ptr = head;
        int i;
        for(i=1;i<=pos-2;i++)
        {
            ptr = ptr->next;
            //Checking is position is invalid
            if(ptr == NULL)
                return head;
        }
        newNode->next = ptr->next;
        ptr->next = newNode;
        return head;
    }

}

//-------------------- tail of the code ------------------------


int rng(int lim) {
	if (lim == 0) return 0;
	return rand()%lim;
}
int a[1000005], sz = 0;
void insertt(int val, int pos) {
	if (pos < 0) return;
	if (pos > sz + 1) return;
	sz += 1;
    int i;
	for (i = sz; i > pos; i--)
		a[i] = a[i - 1];
	a[pos] = val;
}
void erasee(int pos) {
	if (pos > sz) return;
	if (pos < 1) return;
	sz--;
    int i;
	for (i = pos; i <= sz; i++)
		a[i] = a[i + 1];
}
int check(LinkedListNode* head) {
    int i;
	for (i = 1; i <= sz; i++) {
		if (head == NULL) return 0;
		if (head->val != a[i]) return 0;
		head = head->next;
	}	
	if (head != NULL) return 0;
	return 1;
}
int main() {
	srand(time(NULL));
	int t, n; in(t); in(n);
	while (t--) {
		LinkedListNode* head = NULL;
		sz = 0;
        int i;
		for (i = 0; i < n; i++) {
			int type = rng(3);
			if (type == 0) {
				int val = rng(1000);
				head = insertAtBeginning(head, val);
				insertt(val, 1);
				if (n <= 1000 && !check(head)) {
					printf("incorrect insertAtBeginning");
					return 0;
				}
			}

			if (type == 1) {
				int val = rng(1000);
				head = insertAtEnd(head, val);
				insertt(val, sz + 1);
				if (n <= 1000 && !check(head)) {
					printf("incorrect insertAtEnd");
					return 0;
				}
			}

			if (type == 2) {
				int val = rng(1000);
				int pos = rng(sz + 1) + 1;
				head = insertAtPosition(head, val, pos);
				insertt(val, pos);
				if (n <= 1000 && !check(head)) {
					printf("incorrect insertAtPosition");
					return 0;
				}
			}
		}
      	if (!check(head)) {
        	printf("incorrect");
            return 0;
        }
	}
	printf("correct");
}

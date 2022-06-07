#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
}*head = NULL, *sorted = NULL;
typedef struct node N;

void addNode(int value)
{
	N *nn = (N*)malloc(sizeof(N));
	nn->data = value;
	nn->next = head;
	head = nn;
}

void sortedInsert(N *ptr)
{
	if(sorted == NULL || sorted->data >= ptr->data)
	{
		ptr->next = sorted;
		sorted = ptr;
	}
	else
	{
		N *current = sorted;
		while(current->next != NULL && current->data < ptr->data)
			current = current->next;
		ptr->next = current->next;
		current->next = ptr;
	}
}

void sortList()
{
	N *current = head;
	while(current)
	{
		N *next = current->next;
		sortedInsert(current);
		current = next;
	}
	head = sorted;
}

void display()
{
	N *ptr = head;
	while(ptr)
	{
		printf("%d => ",ptr->data);
		ptr = ptr->next;
	}
	printf("NULL\n");
}

int main()
{
	addNode(10);
	addNode(20);
	addNode(15);
	addNode(35);
	addNode(30);
	
	display();
	
	sortList();
	
	display();
	return 0;
}

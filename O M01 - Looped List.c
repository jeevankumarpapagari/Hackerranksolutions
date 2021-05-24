#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"

struct Node{
	int value;
	struct Node* next;
};
typedef struct Node Node;
Node links[105];

void add_link(int from, int to){
	links[from].next = &links[to];
}
void set_value(int index, int val){
	links[index].value = val;
}

int find_loop(Node* head)
{
	Node *ptr = head, *fwdptr = head;
    while(ptr && fwdptr && fwdptr->next)
    {
        ptr = ptr->next;
        fwdptr = fwdptr->next->next;
        if(ptr == fwdptr)
            return 1;
    }
    return 0;
	
}

int main(){
	int i,n,m,tmp,tmp1,tmp2;
	scanf("%d %d", &n, &m);
	for(i = 0; i < n; i++){
		scanf("%d", &tmp);
		set_value(i, tmp);
	}
	for(i = 0; i < m; i++){
		scanf("%d %d", &tmp1, &tmp2);
		add_link(tmp1,tmp2);
	}
	if(find_loop(&links[0]) == 1) printf("Loop Found");
	else printf("No Loop Found");
	return 0;
}

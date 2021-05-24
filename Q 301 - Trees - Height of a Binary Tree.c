#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#define scan(x) scanf(" %d", &x)
struct TreeNode {
	int x;
	struct TreeNode* L;
	struct TreeNode* R;
};
typedef struct TreeNode TreeNode;
TreeNode* newNode(int _x) {
	TreeNode* node = (TreeNode*) malloc(sizeof(TreeNode));
	node->x = _x;
	node->L = node->R = NULL;
    return node;
}
TreeNode* insert(TreeNode* node, int val) {
	if (node == NULL) return newNode(val);
	if (val <= node->x) node->L = insert(node->L, val);
	else node->R = insert(node->R, val);
    return node;
}

/*******************************************************************/
int height(TreeNode* Root)
{
    if(Root == NULL)    return -1;
    else
    {
        int lsth = height(Root->L);
        int rsth = height(Root->R);
        
        if(lsth > rsth) return lsth + 1;
        else            return rsth + 1;
    }
}
/*******************************************************************/

int main() {
	int val, N; scan(N);
	TreeNode* Root = NULL;
    int i;
	for (i = 1; i <= N; i++) {
		scan(val);
		Root = insert(Root, val);
	}
	printf("%d",height(Root));
}

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct binaryTreeNode
{
    int left;
    char ch;
    int right;
};

int main() 
{
    int n,i;
    scanf("%d",&n);  
    struct binaryTreeNode treeOne[n-1],treeTwo[n-1];
    for(i=0;i<n-1;i++)      scanf("%d%d %c",&treeOne[i].left,&treeOne[i].right,&treeOne[i].ch);
    for(i=0;i<n-1;i++)      scanf("%d%d %c",&treeTwo[i].left,&treeTwo[i].right,&treeTwo[i].ch);
    for(i=0;i<n-1;i++)
    {
        if(treeOne[i].left!=treeTwo[i].left || treeOne[i].right!=treeTwo[i].right || treeOne[i].ch==treeTwo[i].ch)
        {
            printf("no");
            return 0;
        }
    }
    printf("yes");
    return 0;
}

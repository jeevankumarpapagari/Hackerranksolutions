#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct node
{
    struct node *link[26];
    int count;
};

struct node* createTRIE()
{
    struct node *newNode = (struct node*) malloc(sizeof(struct node));
    for(int i=0;i<26;i++)
        newNode->link[i] = NULL;
    newNode->count = 0;
    return newNode;
}

void add(struct node *root,char name[])
{
    int i = -1;
    struct node *temp = root;
    while(name[++i])
    {
        if(temp->link[name[i]-'a'] == NULL)
            temp->link[name[i]-'a'] = createTRIE();
        temp = temp->link[name[i]-'a'];
        temp->count++;
    }
}

int find(struct node *root,char str[])
{
    int i = -1;
    struct node *ptr = root;
    while(str[++i])
    {
        if(ptr->link[str[i]-'a']==NULL)
            return 0;
        ptr = ptr->link[str[i]-'a'];
    }
    return ptr->count;
}

int main() 
{
    struct node *root = createTRIE();
    
    int n;
    scanf("%d",&n);
    
    while(n--)
    {
        char name[10];
        scanf("%s",name);
        add(root, name);
    }
    
    char str[10];
    scanf("%s",str);
    
    printf("Number of instances: %d",find(root,str));
    return 0;
}

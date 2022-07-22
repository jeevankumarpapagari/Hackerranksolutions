#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int addqueue(int t, int q[],int v);

int main()
{
    int q;
    scanf("%d",&q);
    
    while(q--)
    {
        int n,m;
        scanf("%d %d",&n,&m);
        int a[n+1][n+1];
        
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=n;j++)
            {
                a[i][j]=-1;
            }
        }
        
        while(m--)
        {
            int u,v;
            scanf("%d %d",&u,&v);
            a[u][v]=6;
            a[v][u]=6;
        }
        int s;
        scanf("%d",&s);
        
        int ans[n+1];
        ans[0]=0;
        ans[s]=0;
        for(int i=1;i<=n;i++)
        {
            if(i!=s)
                ans[i]=-1;
        }
        
        int queue[n];
        queue[0]=s;
        int c=0,top=1;
        while(c!=top)
        {   
            
             for(int i=1;i<=n;i++)
             {
                if(a[queue[c]][i]==6)
                {
                    if(addqueue(top,queue,i))
                    {   
                        queue[top]=i;
                        top++;
                      //  ans[i]=6*(c+1);
                        ans[i]=6+ans[queue[c]];
                    }
                    
                }
             }
            c++;
        }
        for(int i=1;i<=n;i++)
        {
            if(i==s)
                continue;
            else
                printf("%d ",ans[i]);
        } printf("\n");
              
    }    
    return 0;
}

int addqueue(int t, int q[],int v)
{
    for(int i=0;i<t;i++)
    {
        if(q[i]==v)
            return 0;
    }
    return 1;
}


/*       OR         */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
typedef struct node
    {
    int data;
    struct node * next;
}node;
typedef struct list
    {
    node * head;
}list;
void Insert(list *A,int src,int des)
{
    node * temp = malloc(sizeof(node));
    temp -> data  = des;
    temp -> next  = A[src].head;
    A[src].head = temp;
}
void BFS(list *A,int src,int n)
{
    node * temp;
    int i,u,level[n],queue[n];
    int front = 0, rear = 0;
    for(i=0;i<n;i++)
    level[i] = -1;
    queue[front++] = src;
    level[src] = 0;
    while(front>rear)
    {
        u = queue[rear++];
        temp = A[u].head;
        while(temp != NULL)
        {
            if(level[temp->data]==-1)
            {
                queue[front++] = temp->data;
                level[temp->data] = level[u] + 6;
            }
            temp = temp->next;
        }
    }
    
    for(i=0;i<n;i++)
    {
        if(i!=src)
        printf("%d ",level[i]);
    }
    printf("\n");
    
}
int main() {

    int i,j,q,n,m,u,v,s;
    list A[1000];
    scanf("%d",&q);
    for(i=0;i<q;i++)
    {
        scanf("%d%d",&n,&m);
        for(j=0;j<n;j++)
            A[j].head = NULL;
        for(j=0;j<m;j++)
        {
            scanf("%d%d",&u,&v);
            Insert(A,u-1,v-1);
            Insert(A,v-1,u-1);
        }
        
        scanf("%d",&s);
        BFS(A,s-1,n);
    }
    return 0;
}

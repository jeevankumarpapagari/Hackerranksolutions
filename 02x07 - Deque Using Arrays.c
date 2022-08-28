//BASE CODE 

//HEAD

#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "math.h"

//BODY

int deque[500005], head=0,tail=-1;
void push_back(int val)
{
    deque[++tail] = val;
}
void push_front(int val)
{
    if(head == 0)
    {
        tail++;
        for(int i=tail;i>head;i--)
            deque[i] = deque[i-1];
        deque[head] = val;
    }
    else
        deque[--head] = val;
}
int back()
{
    return deque[tail];
}
int front()
{
    return deque[head];
}
void pop_back()
{
    tail--;
}
void pop_front()
{
    head++;
}
int empty()
{
    return head > tail;
}

// TAIL

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        char s[50];
        scanf(" %s", s);
        if (s[0] == 'b')
        {
            if (empty()) printf("invalid\n");
            else printf("%d\n", back());
        }
        if (s[0] == 'f')
        {
            if (empty()) printf("invalid\n");
            else printf("%d\n", front());
        }
        if (s[0] == 'p')
        {
            if (s[1] == 's')
            {
                if (s[2] == 'b')
                {
                    int x; scanf(" %d", &x);
                    push_back(x);
                }
                if (s[2] == 'f')
                {
                    int x; scanf(" %d", &x);
                    push_front(x);
                }       
            }
            else
            {
                if (s[2] == 'b')
                {
                    if (empty()) printf("invalid\n");
                    else pop_back();
                }
                if (s[2] == 'f')
                {
                    if (empty()) printf("invalid\n");
                    else pop_front();
                }
            }
        }
    }
    return 0;
}

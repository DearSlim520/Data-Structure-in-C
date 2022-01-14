#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    struct Node *Next;
    int num;
}*TNode,Node;

int main()
{
    int N,M,i = 0;
    scanf("%d,%d",&N,&M);
    TNode Head,p,q;
    Head = (TNode)malloc(sizeof(Node));
    Head->Next = NULL;
    p = Head;
    for(i = 1;i < N;i++)
    {
        p->num = i;
        q = (TNode)malloc(sizeof(Node));
        p->Next = q;
        p = p->Next;
    }
    p->num = N;
    p->Next = Head;
    p = p->Next;
    i = 1;
    while(1)
    {
        if(p == p->Next)
        {
            printf("%d",p->num);
            break;
        }
        else
        if(i == M)
        {
            printf("%d,",p->Next->num);
            q = p->Next;
            p->Next = q->Next;
            free(q);
            i = 1;
            p = p->Next;
        }
        else
        {
            i++;
            p = p->Next;
        }
    }
    return 0;
}

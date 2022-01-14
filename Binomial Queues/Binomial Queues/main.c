#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define coff 3
#define MAXTREE 20
#define Capacity 100
#define MAXVEX 50

typedef struct BinNode
{
    int Elements;
    struct BinNode *LeftChild;
    struct BinNode *NextSibling;
}BinNode,*BinTree;

typedef struct Collection
{
    int CurrentSize;
    BinTree TheTrees[MAXTREE];
}Collection,*BinQueue;

BinQueue CreateQueue(int X);
BinQueue Merge(BinQueue H1,BinQueue H2);
BinTree CombineTree(BinTree T1,BinTree T2);
void Print(BinTree T);

BinQueue
CreateQueue(int X)
{
    int i = 0;
    BinQueue H;
    H = (BinQueue)malloc(sizeof(Collection));
    if(H == NULL)
    {
        printf("Error1\n");
    }
    
    BinTree T;
    T = (BinTree)malloc(sizeof(BinNode));
    if(T == NULL)
    {
        printf("Error2\n");
    }
    T->LeftChild = T->NextSibling = NULL;
    T->Elements = X;
    
    for(i = 0;i < MAXTREE;i++)
    {
        H->TheTrees[i] = NULL;
    }
    H->CurrentSize = 1;
    H->TheTrees[0] = T;
    
    return H;
}
BinQueue
Merge(BinQueue H1,BinQueue H2)
{
    BinTree T1,T2,Carry;
    int i,j;
    Carry = T1 = T2 = NULL;
    if(H1->CurrentSize + H2->CurrentSize >= Capacity)
    {
        printf("Error3\n");
    }
    H1->CurrentSize += H2->CurrentSize;
    for(i = 0,j = 1;j <= H1->CurrentSize;i++,j *= 2)
    {
        T1 = H1->TheTrees[i];
        T2 = H2->TheTrees[i];
        switch(4*!!Carry+2*!!T2+!!T1)
        {
            case 0:
            case 1:
                break;                                                       //存在t1
            case 2:                                                          //不存在t1,存在t2
                H1->TheTrees[i] = T2;
                H2->TheTrees[i] = NULL;
                break;
            case 3:                                                          //存在t1,t2
                Carry = CombineTree(T1,T2);
                H1->TheTrees[i] = H2->TheTrees[i] = NULL;
                break;
            case 4:                                                          //有了一棵树
                H1->TheTrees[i] = Carry;
                Carry = NULL;
                break;
            case 5:                                                          //一棵树+一个t1
                Carry = CombineTree(T1,Carry);
                H1->TheTrees[i] = NULL;
                break;
            case 6:                                                          //一棵树+一个t2
                Carry = CombineTree(T2,Carry);
                H2->TheTrees[i] = NULL;
                break;
            case 7:                                                          //一棵树+一个t1+一个t2
                H1->TheTrees[i] = Carry;
                Carry = CombineTree(T1,T2);
                H2->TheTrees[i] = NULL;
                break;
        }
    }
    return H1;
}
BinTree
CombineTree(BinTree T1,BinTree T2)
{
    if(T1->Elements > T2->Elements)
    {
        return CombineTree(T2,T1);
    }
    T2->NextSibling = T1->LeftChild;
    T1->LeftChild = T2;
    return T1;
}
void
Print(BinTree T)
{
    if(T)
    {
        Print(T->NextSibling);
        printf("%d,",T->Elements);
        Print(T->LeftChild);
    }
}
int main()
{
    BinTree T1,T2;
    BinQueue H1,H2;
    char str[MAXVEX] = {},*p;
    int A[MAXVEX] = {},N;
    int i = 0,count;
    T1 = T2 = NULL;
    H1 = H2 = NULL;
    scanf("%s",str);
    scanf("%d",&N);
    p = strtok(str,",");
    while(p)
    {
        A[i] = atoi(p);
        p = strtok(NULL,",");
        i++;
    }
    count = i;
    H1 = CreateQueue(A[0]);
    if(count > 1)
    {
        for(i = 1;i < count;i++)
        {
            H2 = CreateQueue(A[i]);
            H1 = Merge(H1,H2);
        }
    }
    
    if(H1->TheTrees[N] == NULL)
    {
        printf("0,");
    }
    else
    {
        Print(H1->TheTrees[N]);
    }
    return 0;
}

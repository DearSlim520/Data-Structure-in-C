 #include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXVEX 100

void HeapJust(int A[],int i,int lenght);
void HeapSort(int A[],int length,int count);
void Swap(int *a,int *b);

void HeapJust(int A[],int i,int length)
{
    int tmp,j;
    tmp = A[i];
    for(j = 2 * i + 1;j < length;j = 2*i + 1)
    {
        if(j < length - 1&&A[j] < A[j + 1])
        {
            j++;
        }
        if(tmp >= A[j])
        {
            break;
        }
        A[i] = A[j];
        i = j;
    }
    A[i] = tmp;
    
}
void HeapSort(int A[],int length,int count)
{
    int i,j = 0;
    if(count != 0)
    {
        for(i = length / 2;i >= 0;i--)
        {
            HeapJust(A,i,length);
        }
        j++;
        if(j != count)
        {
            for(i = length - 1;i > 0;i--)
            {
                Swap(&A[0],&A[i]);
                HeapJust(A,0,i);
                j++;
                if(j == count)
                {
                    break;
                }
            }
        } 
    }
}
void Swap(int *a,int *b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}
int main()
{
    char *p,str[MAXVEX] = {};
    int A[MAXVEX] = {},i = 0,count,j;
    scanf("%s",str);
    p = strtok(str,",");
    while(p)
    {
        A[i] = atoi(p);
        p = strtok(NULL,",");
        i++;
    }
    scanf("%d",&count);
    HeapSort(A,i,count);
    for(j = 0;j < i;j++)
    {
        printf("%d,",A[j]);
    }
    return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXVEX 100
#define LIMIT 5
#define NUMBER 10

void show(int A[],int N);
int GetPosition(int num,int pos);
void RadixSort(int A[],int N,int count);

void
show(int A[],int N)
{
    int i = 0;
    for(i = 0;i < N;i++)
    {
        printf("%d,",A[i]);
    }
}
    int
    GetPosition(int num,int pos)
    {
        int i = 0,tmp = 1;
        for(i = 0;i < pos - 1;i++)
        {
            tmp *= 10;
        }
        num = (num / tmp) % 10;
        return num;
    }
    void
    RadixSort(int A[],int N,int count)
    {
        int i = 0,j = 0,k = 0,pos = 0,num = 0,index = 0;
        int array[MAXVEX][MAXVEX] = {};
        for(i = 0;i < NUMBER;i++)
        {
            array[i][0] = 0;
        }
        for(pos = 1;pos < LIMIT;pos++)
        {
            for(i = 0;i < N;i++)
            {
                num = GetPosition(A[i],pos);
                index = ++array[num][0];
                array[num][index] = A[i];
            }
            for(i = 0,j = 0;i < NUMBER;i++)
            {
                for(k = 1;k <= array[i][0];k++)
                {
                    A[j++] = array[i][k];
                }
                array[i][0] = 0;
            }
            if(pos == count)
                break;
        }
    }
    int main()
    {
        int count,i = 0,A[MAXVEX] = {};
        char *p,str[MAXVEX] = {};
        scanf("%s",str);
        scanf("%d",&count);
        p = strtok(str,",");
        while(p)
        {
            A[i] = atoi(p);
            p = strtok(NULL,",");
            i++;
        }
        RadixSort(A,i,count);
        show(A,i);
        return 0;
    }

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXVEX 100

void ShellSort(int A[],int N,int Increase[]);

void
ShellSort(int A[],int N,int Increase[])
{
    int i,j,k,count = 0,tmp;
    for(k = 0;Increase[k] > 0;k++)
    {
        for(i = Increase[k];i < N;i++)
        {
            tmp = A[i];
            for(j = i;j >= Increase[k];j -= Increase[k])
            {
                if(tmp > A[j - Increase[k]])
                {
                    if(A[j] != A[j - Increase[k]])
                        count++;
                    A[j] = A[j - Increase[k]];
                }
                else
                    break;
            }
            if(A[j] != tmp)
                count++;
            A[j] = tmp;
        }
    }
    printf("%d",count);
}
int main()
{
    int N,Increase[MAXVEX] = {},i = 0,A[] = {3,56,76,13,27,5,18,49,38,65};
    char *p,str[MAXVEX] = {};
    scanf("%d",&N);
    scanf("%s",str);
    p = strtok(str,",");
    while(p)
    {
        Increase[i] = atoi(p);
        p = strtok(NULL,",");
        i++;
    }
    ShellSort(A,10,Increase);
    return 0;
}

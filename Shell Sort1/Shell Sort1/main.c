#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXVEX 100

void ShellSort(int A[],int N);

void
ShellSort(int A[],int N)
{
    int i,j,Increase,k;
    int tmp;
    
    for(Increase = N / 2;Increase > 0;Increase /= 2)
    {
        for(i = Increase; i < N;i++)
        {
            tmp = A[i];
            for(j = i; j >= Increase; j -= Increase)
            {
                if(tmp > A[j - Increase])
                    A[j] = A[j - Increase];
                else
                    break;
            }
            A[j] = tmp;
        }
        for(k = 0;k < N;k++)
        {
            printf("%d,",A[k]);
        }
        printf("\n");
    }
}
int main()
{
    char *p,str[MAXVEX] = {};
    int A[MAXVEX] = {},i = 0,N;
    
    scanf("%d",&N);
    scanf("%s",str);
    p = strtok(str,",");
    while(p)
    {
        A[i] = atoi(p);
        p = strtok(NULL,",");
        i++;
    }
    ShellSort(A,N);
    
}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXVEX 100
int main()
{
    char *p,str[MAXVEX] = {};
    int A[MAXVEX] = {},N,i = 0,j,k,tmp,q;
    
    scanf("%d",&N);
    scanf("%s",str);
    
    p = strtok(str,",");
    while(p)
    {
        A[i] = atoi(p);
        p = strtok(NULL,",");
        i++;
    }
    
    for(i = 0;i < N - 1;i++)
    {
        for(k = i,j = i + 1;j < N;j++)
        {
            if(A[k] > A[j])
            {
                k = j;
            }
        }
        if(i != k)
        {
            tmp = A[i];
            A[i] = A[k];
            A[k] = tmp;
        }
        for(q = 0;q < N;q++)
        {
            printf("%d,",A[q]);
        }
        printf("\n");
    }
    return 0;
}

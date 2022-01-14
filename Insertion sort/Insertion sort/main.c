#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXVEX 100


void Insertion(int A[],int N);

void
Insertion (int A[],int N)
{
    int P,j,k,tmp;
    
    for(P = 1;P < N;P++)
    {
        tmp = A[P];
        for(j = P;A[j - 1] > tmp&&j > 0;j--)
        {
            A[j] = A[j - 1];
        }
        A[j] = tmp;
        for(k = 0;k < N;k++)
        {
            printf("%d,",A[k]);
        }
        printf("\n");
    }
}

int main()
{
    int A[MAXVEX] = {},i = 0,N;
    char *p,str[MAXVEX] = {};
    scanf("%d",&N);
    scanf("%s",str);
    p = strtok(str,",");
    while(p)
    {
        A[i] = atoi(p);
        p = strtok(NULL,",");
        i++;
    }
    Insertion(A,N);
    return 0;
}

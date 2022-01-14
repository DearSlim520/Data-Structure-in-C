#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXVEX 50

typedef struct HuffCode
{
    char word;
    char num[MAXVEX];
}HuffCode;

int main()
{
    HuffCode A[10] ={
        {'a',"1010"},
        {'b',"00"},
        {'c',"10000"},
        {'d',"1001"},
        {'e',"11"},
        {'f',"10001"},
        {'g',"01"},
        {'h',"1011"}
    };
    char inputstr[MAXVEX] = {},codestr[MAXVEX] = {},lenthstr[MAXVEX] = {};
    scanf("%s",inputstr);
    long int strlenth = strlen(inputstr);
    int i,j,k = 0;
    while(strlenth > 0)
    {
        int found = 0;
        for(i = 0; i < 5&&found == 0;i++)
        {
            strncpy(codestr,&inputstr[k],i + 1);
            codestr[i + 1] = '\0';
            for(j = 0;j < 8;j++)
            {
                if(strcmp(codestr,A[j].num) == 0)
                {
                    putchar(A[j].word);
                    k += i + 1;
                    found = 1;
                    strncpy(lenthstr,&inputstr[k],strlenth - 1);
                    break;
                }
            }
        }
        strlenth = strlen(lenthstr);
    }
    
    return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define TABLE_SIZE 10
#define NUMBER_SIZE 12
#define MAXVEX 100
typedef struct HashNode
{
    char number[NUMBER_SIZE];
}HashNode,*Hash;

int main()
{
    int i = 0,currentpos = 0,collision = 0;
    char input[MAXVEX] = {};
    Hash H;
    H = (Hash)malloc(sizeof(HashNode)*TABLE_SIZE);
    memset(H,0,sizeof(HashNode)*TABLE_SIZE);
    scanf("%s",input);
    do {
        currentpos = input[i + 10] - 48;
        if((H[currentpos]).number[0] == '\0')
        {
            memcpy((H[currentpos]).number,&input[i],11);
        }
        else {
            collision = 1;
            while((H[(currentpos + collision*collision)%TABLE_SIZE]).number[0] != '\0')
            {
                collision++;
            }
            currentpos = (currentpos + collision*collision) % TABLE_SIZE;
            memcpy((H[currentpos]).number,&input[i],11);
        }
        i += NUMBER_SIZE;
    } while (input[i] != '\0');
    for(i = 0;i < TABLE_SIZE;i++)
    {
        if((H[i]).number[0] == '\0')
        {
            printf("0");
            if(i < TABLE_SIZE - 1)
            {
                printf(",");
            }
        }
        else
        {
            printf("%s,",(H[i]).number);
        }
    }
    return 0;
}

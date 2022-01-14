#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXVEX 100

typedef struct stack
{
    int Capacity;
    int TopStack;
    char array[MAXVEX];
    float array2[MAXVEX];
}stack,*TStack;

TStack CreateStack(void);
void push(TStack S,char ch);
void pusu2(TStack S,float num);
void pop(TStack S);
char top(TStack S);
float top2(TStack S);
int Compare(char ch1,char ch2);

TStack
CreateStack()
{
    TStack S;
    S = (TStack)malloc(sizeof(stack));
    S->Capacity = MAXVEX;
    if(S != NULL)
    {
        S->TopStack = -1;
    }
    return S;
}
void
push(TStack S,char ch)
{
    S->array[++S->TopStack] = ch;
}
void
push2(TStack S,float num)
{
    S->array2[++S->TopStack] = num;
}
void
pop(TStack S)
{
    S->TopStack--;
}
char
top(TStack S)
{
    return S->array[S->TopStack];
}
float
top2(TStack S)
{
    return S->array2[S->TopStack];
}
int
Compare(char ch1,char ch2)
{
    int flag1 = 0,flag2 = 0;
    if(ch1 == '+'||ch1 == '-')
    {
        flag1 = 1;
    }
    if(ch1 == '*'||ch1 == '/')
    {
        flag1 = 2;
    }
    if(ch2 == '+'||ch2 == '-')
    {
        flag2 = 1;
    }
    if(ch2 == '*'||ch2 == '/')
    {
        flag2 = 2;
    }
    if(flag1 > flag2)
    {
        return 2;
    }
    else if(flag1 == flag2)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
int main()
{
    char input[MAXVEX] = {},str[MAXVEX] = {};
    int i = 0,k = 0;
    scanf("%s",input);
    TStack S;
    S = CreateStack();
    for(i = 0;i < strlen(input);i++)
    {
        if(input[i] >= '0'&&input[i] <= '9')
        {
            str[k++] = input[i];
        }
        else
        {
            if(input[i] == '(')
            {
                push(S,input[i]);
            }
            else if(input[i] == ')')
            {
                while(top(S) != '(')
                {
                    str[k++] = top(S);
                    pop(S);
                }
                pop(S);
            }
            else
            {
                while(S->TopStack != -1&&top(S) != '('&&Compare(input[i],top(S))!= 2)
                {
                    str[k++] = top(S);
                    pop(S);
                }
                push(S,input[i]);
            }
        }
    }
    while(S->TopStack != -1)
    {
        str[k++] = top(S);
        pop(S);
    }
    float num1 = 0.0,num2 = 0.0,newnum = 0.0;
    for(i =0;i < strlen(str);i++)
    {
        if(str[i] >= '0'&&str[i] <= '9')
        {
            newnum = (float)str[i] - 48;
            push2(S,newnum);
        }
        else
        {
            num1 = top2(S);
            pop(S);
            num2 = top2(S);
            pop(S);
            if(str[i] == '+')
            {
                newnum = num1 + num2;
            }
            else if(str[i] == '-')
            {
                newnum = num2 - num1;
            }
            else if(str[i] == '*')
            {
                newnum = num1 * num2;
            }
            else
            {
                newnum = num2 / num1;
            }
            push2(S,newnum);
        }
    }
    printf("%.2f\n",top2(S));
    for(i = 0;i < strlen(str);i++)
    {
        printf("%c ",str[i]);
    }
    return 0;
}

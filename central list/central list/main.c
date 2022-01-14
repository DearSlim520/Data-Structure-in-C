#include<stdio.h>
#define MAXVEX 100

int main()
{
    int a,b,flag = 1;
    char str[MAXVEX] = {};
    scanf("%s",str);
    for(a = 0;str[a] != '\0';a++)
    {
        b = a / 2;
    }
    for(a = 0;b - a >= 0;a++)
    {
        if(str[b + a] == str[b - a])
        {
            flag = 1;
        }
        else
        {
            printf("No");
            flag = 0;
            break;
        }
    }
    if(flag == 1)
    {
        printf("Yes");
    }
    return 0;
}

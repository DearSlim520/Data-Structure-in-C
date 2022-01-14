#include<stdio.h>
#define Cutoff (3)
#define MAXVEX 100

void QuickSort(int A[],int N,int pivot);
void Qsort(int A[],int Left,int Right,int pivot);
void InsertionSort(int A[],int N);
void Swap(int *a,int *b);
int Median3(int A[],int Left,int Right);

void
QuickSort(int A[],int N,int pivot)
{
    Qsort(A,0,N - 1,pivot);
}
void
Qsort(int A[],int Left,int Right,int pivot)
{
    int pivotvalue;
    static int count = 1;
    int k = 0;
    if(Left + Cutoff <= Right)
    {
        if(count == 1)
        {
            pivotvalue = A[pivot];
            if(A[pivot] != A[Right])
            {
                Swap(&A[pivot],&A[Right]);
            }
        }
        else
        {
            pivotvalue = Median3(A,Left,Right);
        }
        int left1 = Left,right1 = Right - 1;
        if(count == 1)
        {
            for(; ;)
            {
                while(A[left1] < pivotvalue)
                {
                    left1++;
                }
                while(A[right1] > pivotvalue)
                {
                    right1--;
                }
                if(left1 < right1)
                {
                    Swap(&A[left1],&A[right1]);
                }
                else
                {
                    break;
                }
            }
        }
        else
        {
            for(; ;)
            {
                while(A[++left1] < pivotvalue){}
                while(A[--right1] > pivotvalue){}
                if(left1 < right1)
                {
                    Swap(&A[left1],&A[right1]);
                }
                else
                {
                    break;
                }
            }
            
        }
        if(count == 1)
        {
            Swap(&A[left1],&A[Right]);
            count++;
        }
        else
        {
            Swap(&A[left1],&A[Right - 1]);
        }
        printf("Qsort(%d,%d):",Left,Right);
        for(k = 0;k < 10;k++)
        {
            printf("%d,",A[k]);
        }
        printf("\n");
        Qsort(A,Left,left1 - 1,pivot);
        Qsort(A,left1 + 1,Right,pivot);
    }
    else
    {
        InsertionSort(A + Left,Right - Left + 1);
        printf("insert(%d,%d):",Left,Right - Left + 1);
        for(k = 0;k < 10;k++)
        {
            printf("%d,",A[k]);
        }
        printf("\n");
    }
}
void
InsertionSort(int A[],int N)
{
    int j,P;
    int tmp;
    for(P = 1;P < N;P++)
    {
        tmp = A[P];
        for(j = P;j > 0&&A[j - 1] > tmp;j--)
        {
            A[j] = A[j - 1];
        }
        A[j] = tmp;
    }
}
void
Swap(int *a,int *b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}
int
Median3(int A[],int Left,int Right)
{
    int center = (Left + Right) / 2;
    if(A[Left] > A[center])
        Swap(&A[Left],&A[center]);
    if(A[Left] > A[Right])
        Swap(&A[Left],&A[Right]);
    if(A[center] > A[Right])
        Swap(&A[center],&A[Right]);
    Swap(&A[center],&A[Right - 1]);
    return A[Right - 1];
}
int main()
{
    int A[] = {49,38,65,97,76,13,27,50,2,8};
    int N = 10;
    int pivot = 0;
    scanf("%d",&pivot);
    QuickSort(A,N,pivot);
}

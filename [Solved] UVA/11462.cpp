#include <iostream>
#include<stdio.h>
#include <cstdlib>
    int a[2000001];
int compare_ints(const void* a, const void* b)   // comparison function
{
    int* arg1 = (int*) a;
    int* arg2 = (int*) b;
    if (*arg1 < *arg2) return -1;
    else if (*arg1 == *arg2) return 0;
    else return 1;
}

int main()
{

    int i,j,n,size;
    while(scanf("%d",&n))
    {
        if(n==0)
        {
            break;
        }
        j=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        size=n;
        std::qsort(a, size, sizeof(int), compare_ints);

        for (int i = 0; i < size; i++)
        {
            if(j!=0)
            {
                printf(" ");
            }
            printf("%d",a[i]);
            j=1;
        }
        printf("\n");
    }
return 0;
}

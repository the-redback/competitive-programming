#include <iostream>
#include<stdio.h>
#include <algorithm>
int a[2000001];

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
        std::sort(a,a+n);

        for (int i = 0; i < n; i++)
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

#include <stdio.h>
#include <cstdlib>
using namespace std;
int arr[500001],ab[500001];
int compare(const void *a, const void *b)
{
    int *ia=(int*) a;
    int *ib=(int*) b;
    return (*ia-*ib);
}

main()
{
    int i,j,n;
    while(scanf("%d",&n))
    {
        if(n==0)
        {
            break;
        }
        for(i=0;i<n;i++)
        {
            scanf("%d %d",&arr[i],&ab[i]);
        }
        qsort(arr,n,sizeof(int),compare);
        qsort(ab,n,sizeof(int),compare);
        for(i=0;i<n;i++)
        {
            if(arr[i]!=ab[i])
            {
                break;
            }
        }
        if(i==n)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}

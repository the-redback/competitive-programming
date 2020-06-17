#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

main()
{
    int a[10001],b[10001];
    int m=0,n,q,i,j;
    while(scanf("%d %d",&n,&q))
    {
        if(n==0 && q==0)
            return 0;

        m++;
        printf("CASE# %d:\n",m);

        for(i=0; i<n; i++)
            scanf("%d",&a[i]);

        for(i=0; i<q; i++)
            scanf("%d",&b[i]);

        sort(a,a+n);

        for(i=0; i<q; i++)
        {
            for(j=0; j<n; j++)
            {
                if(b[i]==a[j])
                {
                    printf("%d found at %d\n",b[i],j+1);
                    break;
                }
            }
            if(j==n)
            {
                printf("%d not found\n",b[i]);
            }
        }
    }
    return 0;
}

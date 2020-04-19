#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;

main()
{
    int t,n,i,j,count;
    int a[11];
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d",&n);
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[j]);
        }
        count=ceil((a[0]-2)/5.0);
        for(j=1;j<n;j++)
        {
            count+=ceil((a[j]-a[j-1])/5.0);
        }
        printf("Case %d: %d\n",i,count);
    }
    return 0;
}

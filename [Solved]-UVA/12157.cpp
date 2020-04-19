#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;

main()
{
    int i,sum1,sum2,cost1,cost2,j,m,n,t,T;
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        sum1=0;
        sum2=0;
        scanf("%d",&n);
        while(n--)
        {
            scanf("%d",&m);
            sum1+=(m/30)+1;
            sum2+=(m/60)+1;
        }
        cost1=sum1*10;
        cost2=sum2*15;
        if(cost1<cost2)
            printf("Case %d: Mile %d\n",t,cost1);
        else if(cost2<cost1)
            printf("Case %d: Juice %d\n",t,cost2);
        else
            printf("Case %d: Mile Juice %d\n",t,cost2);
    }
    return 0;
}

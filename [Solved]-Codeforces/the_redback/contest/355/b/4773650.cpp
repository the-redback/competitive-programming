#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
#include<stack>
using namespace std;
main()
{
    int i,j,k,l,m,n;
    long c1,c2,c3,c4,sum1,sum2,sum3,sum;
    while(~scanf("%ld%ld%ld%ld",&c1,&c2,&c3,&c4))
    {
        scanf("%d%d",&n,&m);
        sum1=0;
        for(i=0; i<n; i++)
        {
            scanf("%d",&j);
            k=min(j*c1,c2);
            sum1+=k;
        }
        sum1=min(sum1,c3);
        sum2=0;
        for(i=0; i<m; i++)
        {
            scanf("%d",&j);
            k=min(j*c1,c2);
            sum2+=k;
        }
        sum2=min(sum2,c3);
        sum=min(sum1+sum2,c4);
        printf("%ld\n",sum);
    }
    return 0;
}

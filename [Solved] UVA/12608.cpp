#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

struct data
{
    int x;
    int w;
};
main()
{
    int k,y,m,n,t=1,i,tc;
    long long sum,carry;
    data a[2000];
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d%d",&m,&n);
        for(i=1;i<=n;i++)
        {
            scanf("%d%d",&a[i].x,&a[i].w);
        }
        a[0].x=0;
        sum=0;
        carry=0;
        for(i=1;i<=n;i++)
        {
            if(carry+a[i].w>m)
            {
                sum+=a[i].x-a[i-1].x;
                sum+=a[i].x*2;
                carry=a[i].w;
            }
            else if(carry+a[i].w==m && i!=n )
            {
                sum+=a[i].x-a[i-1].x;
                sum+=a[i].x*2;
                carry=0;
            }
            else
            {
                carry+=a[i].w;
                    sum+=a[i].x-a[i-1].x;
            }
        }
        sum+=a[n].x;
        printf("%lld\n",sum);
    }
    return 0;
}

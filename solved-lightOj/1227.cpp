#include <cstdio>

main()
{
    int t,n,p,k,q,i,sum,count;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        sum=0;
        count=0;
        scanf("%d%d%d",&n,&p,&q);
        while(n--)
        {
            scanf("%d",&k);
            if(count<p && (sum+k)<=q)
            {
                count++;
                sum+=k;
            }
        }
        printf("Case %d: %d\n",i,count);
    }
    return 0;
}

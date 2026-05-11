/**
 *                                   ____
 *       ____ ___  ____ ________  __/ __/
 *      / __ `__ \/ __ `/ ___/ / / / /_
 *     / / / / / / /_/ / /  / /_/ / __/
 *    /_/ /_/ /_/\__,_/_/   \__,_/_/
 *
 *    @link : https://the-redback.com
 */
#include <bits/stdc++.h>
using namespace std;
#define inf HUGE_VAL
#define mem(a,b) memset(a,b,sizeof(a))

#define NN 5000001
unsigned long long a[NN+7];
void sieve(void)
{
    int i,j,k,n=2237;
    for(i=2;i<NN;i++)
        a[i]=i;
    for(i=2;i<NN;i+=2)
    {
        a[i]*=(2-1);
        a[i]/=2;
    }
    for(i=3;i<NN;i+=2)
        if(a[i]==i)
        {
            for(j=i;j<NN;j+=i)
            {
                a[j]*=(i-1);
                a[j]/=i;
            }
        }
}

main()
{
    sieve();
    int tc,t=1;
    int i,j,k,l,x;
    for(i=2;i<NN;i++)
    {
        a[i]*=a[i];
        a[i]+=a[i-1];
    }
    printf("%llu");
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d%d",&k,&l);
        printf("Case %d: %llu\n",t++,a[l]-a[k-1]);
    }
    return 0;
}

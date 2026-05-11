
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
int phi(int n)
{
    int res=n;
    int i;
    for(i=2;i*i<=n;i++)
    {
        if(!(n%i))
            res-=res/i;
        while(!(n%i))
        {
            n/=i;
        }
        if(n==1)
            break;
    }
    if(n>1)
        res-=res/n;
    return res;
}

main()
{
    int tc,t=1;
    int i,j,k,l,x;
    //scanf("%d",&tc);
    while(~scanf("%d",&k))
    {
       // l=k;
        if(k==0)
            return 0;
        l=phi(k);
        if(k==1)
            l=0;
        printf("%d\n",l);
    }
    return 0;
}

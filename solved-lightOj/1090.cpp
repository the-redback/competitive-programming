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


int go(int n,int r)
{
    int sum=0,i=1;
    while(1)
    {
        long long k=pow(r,i);
        if(k>n)
            break;
        sum+=n/k;
        i++;
    }
    return sum;
}

int pq(int n,int r)
{
    int count=0;
    while(n%r==0)
    {
        count++;
        n/=r;
    }
    return count;
}

main()
{
    int n,k,l;
    int a,b,c,d;
    int tc,t=1;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d%d%d%d",&a,&b,&c,&d);
        k=go(a,2);
        l=go(a,5);
        k+=pq(c,2)*d;
        l+=pq(c,5)*d;
        k-=go(b,2);
        l-=go(b,5);
        k-=go(a-b,2);
        l-=go(a-b,5);
        k=min(k,l);
        if(k<0)
            k=0;
        printf("Case %d: %d\n",t++,k);
    }
    return 0;
}

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
#define MAX 9999999
bool pr[MAX+7];
vector<int>v;
void sieve(int n)
{
    long long i,j;
    for(i=4;i<n;i+=2)
        pr[i]=1;
    for(i=3;i<n;i+=2)
        if(!pr[i])
            for(j=i*i;j<n;j+=2*i)
                pr[j]=1;
    for(i=2;i<n;i++)
        if(!pr[i])
            v.push_back(i);
}


long long divisor(long long n)
{
    if(n<0)
        n*=-1;
    long long res;
    int flag=0,i,j;
    int sz=v.size();
    for(j=0;j<sz && v[j]*v[j]<=n;j++)
    {
        i=v[j];
        if(!(n%i))
        {
            //cout<<i<<" ";
            flag++;
            res=i;
        }
        while(!(n%i))
        {
            n/=i;
        }
        if(n==1)
            break;
    }
    if(n>1)
    {
        flag++;
        res=n;
    }
    if(flag<=1)
        return -1;
    return res;
}

main()
{
    sieve(MAX+1);
    int tc,t=1;
    long long K;
    //scanf("%d",&tc);
    while(~scanf("%lld",&K))
    {
        if(K==0)
            return 0;
        K=divisor(K);
        printf("%lld\n",K);
    }
    return 0;
}


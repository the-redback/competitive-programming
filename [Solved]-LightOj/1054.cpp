/**
 *    @author     : Maruf Tuhin
 *    @School     : CUET CSE 11
 *    @Topcoder   : the_redback
 *    @Codeforces : the_redback
 *    @UVA        : Redback
 *    @link       : http://www.fb.com/maruf.2hin
 */
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<set>
#include<sstream>
#include<stack>
using namespace std;
#define inf HUGE_VAL
#define mem(a,b) memset(a,b,sizeof(a))
#define mod 1000000007
#define NN 46340

long long sum;
long long pwr;
bool p[NN+7];
vector<int>pr;
void sieve(int n)
{
    int i,j,k,l;
    p[1]=1;
    pr.push_back(2);
    for(i=4;i<=n;i+=2)
        p[i]=1;
    for(i=3;i<=n;i+=2)
    {
        if(p[i]==0)
        {
            pr.push_back(i);
            for(j=i*i;j<=n;j+=2*i)
                p[j]=1;
        }
    }
}

long long go(int n,long long q)
{
    if(q==1)
        return n%mod;
    if(q%2)
        return ((n%mod)*go(n,q-1))%mod;
    else
    {
        long long k=go(n,q/2);
        return (k*k)%mod;
    }
}

void factor(int n)
{
    int i;
    long long k,cnt,r,in;
    for(i=0;i<pr.size() && (long long) pr[i]*pr[i]<=n;i++)
    {
        k=pr[i];
        cnt=0;
        while(n%k==0)
        {
            n/=k;
            cnt++;
        }
        if(cnt>0)
        {
            r=((cnt*pwr)+1);
            r=go(k,r)-1;
            in=go(k-1,mod-2);
            r=(r*in)%mod;
            sum=(sum*r)%mod;
        }
        if(n==1)
            break;
    }
    if(n>1)
    {
        r=pwr+1;
        r=(go(n,r)+mod-1)%mod;
        in=go(n-1,mod-2);
        r=(r*in)%mod;
        sum=(sum*r)%mod;
    }
}

main()
{
    sieve(NN);
    int n,k,l,r,i;
    int tc,t=1;
    scanf("%d",&tc);
    while(tc--)
    {
        sum=1;
        scanf("%d%lld",&n,&pwr);
        factor(n);
        printf("Case %d: %lld\n",t++,sum);

    }
    return 0;
}

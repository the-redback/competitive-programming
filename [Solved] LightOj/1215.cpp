/**
 *    @author     : Maruf Tuhin
 *    @College    : CUET CSE 11
 *    @Topcoder   : the_redback
 *    @CodeForces : the_redback
 *    @UVA        : the_redback
 *    @link       : http://www.fb.com/maruf.2hin
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef unsigned long long llu;

#define ft        first
#define sd        second
#define mp        make_pair
#define pb(x)     push_back(x)
#define all(x)    x.begin(),x.end()
#define allr(x)   x.rbegin(),x.rend()
#define mem(a,b)  memset(a,b,sizeof(a))
#define inf       1e9
#define eps       1e-9
#define mod       1000000007

#define read(a)   scanf("%lld",&a)

#define NN 1000010
ll a[NN],b[NN],c[NN];
bool p[NN+7]; //Hashing
vector<ll>pr; //storing prime
void sieve(ll n)
{
    ll i,j,k,l;
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

ll factor(ll n)
{
    ll count,k,i;
    for(i=0;i<pr.size() && pr[i]*pr[i]<=n;i++)
    {
        k=pr[i];
        count=0;
        while(n%k==0)
        {
            n/=k;
            count++;
        }
        a[k]=max(a[k],count);
        if(n==1)
            break;
    }
    if(n>1)
        a[n]=max(a[n],1LL);
}

ll factor2(ll n)
{
    ll count,k,i;
    for(i=0;i<pr.size() && pr[i]*pr[i]<=n;i++)
    {
        k=pr[i];
        count=0;
        while(n%k==0)
        {
            n/=k;
            count++;
        }
        b[k]=count;
        if(n==1)
            break;
    }
    if(n>1)
    {
        if(n>1000000)
            return n;
        b[n]=1;
    }
    return 1;
}



ll power(ll n,ll k)
{
    ll sum=1;
    while(k--)
        sum*=n;
    return sum;
}

main()
{
#ifdef redback
    freopen("C:\\Users\\Maruf\\Desktop\\in.txt","r",stdin);
#endif // redback
    sieve(NN);

    //ios_base::sync_with_stdio(0); cin.tie(0);
    ll t=1,tc;
    read(tc);
    ll i,j,k,l,m,n;
    while(tc--)
    {
        read(m);
        read(n);
        read(l);
        mem(a,0);
        mem(b,0);
        ll flag=0;
        factor(n);
        factor(m);
        k=factor2(l);
        llu sum=k;
        for(i=2;i<=1000000;i++)
        {
            if(a[i]>b[i])
            {
                flag=1;
                break;
            }
            if(b[i]-a[i]>0)
                sum*=power(i,b[i]);
        }
        if(flag)
        {
            printf("Case %lld: impossible\n",t++);
            continue;
        }
        printf("Case %lld: %llu\n",t++,sum);
    }

    return 0;
}


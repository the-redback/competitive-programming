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
#define NN        100010

#define read(a)   scanf("%lld",&a)

#define NN 1000001

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
    ll sum=1;
    ll count,k,i;
    for(i=0;i<pr.size() && pr[i]*pr[i]<=n;i++)
    {
        k=pr[i];
        count=0;

        if(n%k==0)
            sum*=k;

        while(n%k==0)
        {
            n/=k;
            count++;
        }
        if(n==1)
            break;
    }
    if(n>1)
	{
	    sum*=n;
	}
	return sum;
}


int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    #ifdef redback
        freopen("C:\\Users\\Maruf\\Desktop\\in.txt","r",stdin);
    #endif

    sieve(NN);
    ll t=1,tc;
    //read(tc);
    ll i,j,k,l,m,n;
    while(~read(n))
    {

        ll ans=factor(n);
        printf("%lld\n",ans);

    }
    return 0;
}

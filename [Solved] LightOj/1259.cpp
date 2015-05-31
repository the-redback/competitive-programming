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

#define read(a) scanf("%lld",&a)

#define NN 10000000
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

main()
{
    sieve(NN);
    ll t=1,tc;
    read(tc);
    ll i,j,k,l,m,n;
    while(tc--)
    {
        read(n);
        ll mid=n/2;
        vector<ll>::iterator ind;
        ind=lower_bound(pr.begin(),pr.end(),mid);
        ll in=ind-pr.begin();
        ll low=in,high=in;
        ll ans=0;
        while(low>=0 && high<pr.size() && pr[high]<n)
        {
            //cout<<pr[low]<<" "<<pr[high]<<" "<<pr[low]+pr[high]<<"\n";
            if(pr[low]+pr[high]==n)
            {
                ans++;
                low--;
                high++;
            }
            if(pr[low]+pr[high]>n)
                low--;
            if(pr[low]+pr[high]<n)
                high++;
        }
        printf("Case %lld: %lld\n",t++,ans);

    }
    return 0;
}

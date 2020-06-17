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


ll a[100];
ll b[100];
ll c[100];


int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    #ifdef redback
        freopen("C:\\Users\\Maruf\\Desktop\\in.txt","r",stdin);
    #endif

    ll t=1,tc;
    //read(tc);
    ll i,j,k,l,m,n;
    while(~read(n))
    {
        mem(a,0);
        mem(b,0);
        for(i=1;i<n;i++)
            read(a[i]);
        for(i=1;i<n;i++)
            read(b[i]);
        for(i=0;i<n;i++)
            read(c[i]);

        a[0]=0;
        b[n]=0;

        for(i=1;i<n;i++)
        {
            a[i]+=a[i-1];
        }

        for(i=n-1;i>=1;i--)
        {
            b[i]+=b[i+1];
        }

        vector<ll>ans;

        for(i=0;i<n;i++)
        {
            ll sum=a[i]+b[i+1]+c[i];
            ans.pb(sum);
        }
        sort(all(ans));

        ll an=ans[0]+ans[1];
        printf("%lld\n",an);

    }
    return 0;
}

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



ll power(ll n,ll k)
{
    ll ans=1;
    while(k--)
    {
        ans*=n;
    }
    return ans;
}

main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
#ifdef redback
    freopen("C:\\Users\\Maruf\\Desktop\\in.txt","r",stdin);
#endif

    ll t=1,tc;
    //read(tc);
    ll i,j,h,k,l,x,y,xx,yy,m,n;
    while(cin>>h>>n)
    {
        ll total=0;

        ll fl=-1;
        ll pos=1;
        ll ans=0;

        while(h>0)
        {
            total=0;
            for(i=0; i<=h; i++)
            {
                total+=power(2,i);
            }
            ll last=power(2,h);
            h--;
            ll mid=(1+total)/2;
            ll mm=last/2;
            last-=mm;
            if(n<=mm)
            {
                if(fl==1 || fl==-1)
                {
                    ans++;
                    // total--;
                }
                else
                {
                    ans+=mid;
                    //total-=mid;
                }
                fl=0;
            }
            else
            {
                if(fl==0)
                {
                    ans++;
                    //  total--;
                }
                else
                {
                    ans+=mid;
                    // total-=mid;
                }
                n-=mm;
                fl=1;
            }
        }
        cout<<ans<<"\n";

    }
    return 0;
}


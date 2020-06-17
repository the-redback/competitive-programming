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

ll a[NN];
vector<ll>v;


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
        for(i=0;i<n;i++)
            read(a[i]);
        sort(a,a+n);

        ll fst=-1,last=-1;

        for(i=n-1;i>0;i--)
        {
            if((a[i]-a[i-1])<=1)
            {

                v.pb(a[i-1]);
                i--;
            }
        }

        ll ans=0;

        for(i=0;i<v.size();i++)
        {
            if(fst==-1)
            {
                fst=v[i];
            }
            else if(last==-1)
                last=v[i];

            if(fst!=-1 && last!=-1)
            {
                ans+=fst*last;
                fst=-1;
                last=-1;
            }
        }

        printf("%lld\n",ans);
        v.clear();


    }
    return 0;
}

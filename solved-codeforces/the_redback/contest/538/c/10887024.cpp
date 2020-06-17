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


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifdef redback
        freopen("C:\\Users\\Maruf\\Desktop\\in.txt","r",stdin);
    #endif

    ll t=1,tc;
    ll i,j,k,l,m,n;
    while(cin>>n>>m)
    {
        ll ld,lh;
        ll nd,nh;

        ll mx=0;

        cin>>ld>>lh;

        mx=lh+(ld-1);

        for(i=0;i<m-1;i++)
        {
            cin>>nd>>nh;

            if(abs(nh-lh)>(nd-ld))
            {
                cout<<"IMPOSSIBLE\n";
                return 0;
            }
            if(nh>=lh)
            {
                k=nh-lh;
                l=ld+k;

                ll ret=nh+(nd-l)/2;
                mx=max(mx,ret);
            }
            else
            {
                k=lh-nh;
                l=ld+k;

                ll ret=lh+(nd-l)/2;
                mx=max(mx,ret);
            }
            lh=nh;
            ld=nd;
        }
        ll rr=(n-ld)+lh;
        mx=max(mx,rr);

        cout<<mx<<"\n";

    }
    return 0;
}

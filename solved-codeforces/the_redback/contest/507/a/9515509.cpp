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


vector< pair<ll,ll> >v;
vector<ll>ans;

main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    #ifdef redback
        freopen("C:\\Users\\Maruf\\Desktop\\in.txt","r",stdin);
    #endif

    ll t=1,tc;
    //read(tc);
    ll i,j,k,l,m,n;
    while(cin>>n>>k)
    {
        ans.clear();
        v.clear();
        for(i=0;i<n;i++)
        {
            cin>>l;
            v.pb(mp(l,i+1));
        }
        sort(all(v));
        ll ret=0;
        for(i=0;i<n;i++)
        {
            if(v[i].ft+ret<=k)
            {
                ret+=v[i].ft;
                ans.pb(v[i].sd);
            }
        }
        l=(ll)ans.size();
        cout<<l<<"\n";
        for(i=0;i<ans.size();i++)
        {
            if(i!=0)
                cout<<" ";
            cout<<ans[i];
        }
        cout<<"\n";

    }
    return 0;
}


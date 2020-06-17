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
#define NN        30100

//#define read(a)   scanf("%lld",&a)

ll a[3010],b[3030];
ll fl[3030];
vector<pair<ll, ll> >v;
main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t=1,tc;
    //cin>>tc;
    ll i,j,k,l,m,n;
    while(cin>>n)
    {
        for(i=0;i<n;i++)
            cin>>a[i],b[i]=a[i];
        sort(b,b+n);
        ll  cnt=0;
        v.clear();
        for(i=0;i<n;i++)
        {
            if(a[i]!=b[i])
            {
                for(j=i+1;j<n;j++)
                {
                    if(a[j]==b[i])
                    {
                        cnt++;
                        swap(a[i],a[j]);
                        v.pb(mp(i,j));
                        break;
                    }
                }
            }
        }
        cout<<cnt<<"\n";
        for(i=0;i<v.size();i++)
        {
            cout<<v[i].ft<<" "<<v[i].sd<<"\n";
        }

    }
    return 0;
}

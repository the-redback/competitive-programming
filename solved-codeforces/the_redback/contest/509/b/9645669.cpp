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
#define NN        111

#define read(a)   scanf("%lld",&a)


ll a[NN];
ll ans[NN][NN];
ll flag[NN];

main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
#ifdef redback
    freopen("C:\\Users\\Maruf\\Desktop\\in.txt","r",stdin);
#endif

    ll t=1,tc;
    //read(tc);
    ll i,j,k,l,m,n;
    while(cin>>n>>m)
    {
        mem(ans,0);
        ll ret=inf;
        for(i=1; i<=n; i++)
        {
            cin>>a[i];
            ret=min(ret,a[i]);
        }
        for(i=1; i<=n; i++)
        {
            ans[i][1]=ret;
            a[i]-=ret;
        }
        j=2;
        for(j=1; j<=m; j++)
        {
            for(i=1; i<=n; i++)
            {
                if(a[i]!=0)
                {
                    ans[i][j]++;
                    a[i]--;
                }
            }
        }
        ret=1;
        if(a[1]>0)
            ret=0;
        for(i=2;i<=n && ret;i++)
        {
            if(a[i]>0)
                ret=0;
            ll total=0;
            for(j=1;j<=m && ret;j++)
            {
                if(abs(ans[i][j]-ans[i-1][j])>1)
                {
                    ret=0;
                    break;
                }
            }
        }
        if(ret==0)
        {
            cout<<"NO\n";
            continue;
        }
        cout<<"YES\n";

        mem(flag,0);
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                k=ans[i][j];
                for(ll jj=0;jj<k;jj++)
                {
                    if(flag[i]!=0)
                        cout<<" ";
                    cout<<j;
                    flag[i]=1;
                }
            }
            cout<<"\n";
        }
    }
    return 0;
}


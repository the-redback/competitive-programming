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
#define NN        300000

#define read(a)   scanf("%lld",&a)

pair<ll,ll>a[NN];
ll N;

ll srch_1st(ll num)
{
    ll low=1;
    ll high=N;

    while(low<=high)
    {
        ll mid=(low+high)/2.0;
        if(a[mid].ft==num)
            return mid;
        else if(a[mid].ft<num)
            low=mid+1;
        else
            high=mid-1;
    }
    return -1;
}

ll srch_2nd(ll num)
{
    ll low=1;
    ll high=N;

    while(low<=high)
    {
        ll mid=(low+high)/2.0;
        if(a[mid].sd==num)
            return mid;
        else if(a[mid].sd<num)
            low=mid+1;
        else
            high=mid-1;
    }
    return -1;
}

bool comp(pair<ll,ll>aa,pair<ll,ll>bb)
{
    if(aa.sd==bb.sd)
        return aa.ft<bb.ft;
    return aa.sd<bb.sd;
}

ll b[NN];

int c[1000010];
int d[1000010];

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t=1,tc;
    //cin>>tc;
    ll i,j,k,l,m,n;
    while(cin>>n)
    {
        N=n;
        mem(c,0);
        mem(d,0);
        ll mx=0;
        for(i=1; i<=n; i++)
        {
            cin>>a[i].ft>>a[i].sd;
            k=a[i].ft;
            l=a[i].sd;
            mx=max(mx,k);
            mx=max(mx,l);
            c[k]++;
            c[l]++;
            d[k]=1;
            d[l]=2;
        }
        sort(a+1,a+n+1);
        i=0;
        ll num=0;
        while(i+2<=n)
        {
            ll mid=srch_1st(num);
            b[i+2]=a[mid].sd;
            num=a[mid].sd;
            i+=2;
        }

        if(n%2==0)
        {
            i=n+1;
            num=0;
            sort(a+1,a+n+1,comp);
            while(i-2>=1)
            {
                ll mid=srch_2nd(num);
                b[i-2]=a[mid].ft;
                num=a[mid].ft;
                i-=2;
            }
        }
        else
        {
            num=0;
            for(i=1; i<=mx; i++)
                if(c[i]==1 && d[i]==1)
                {
                    num=i;
                    break;
                }
            i=1;
            b[i]=num;
            while(i+2<=n)
            {
                ll mid=srch_1st(num);
                b[i+2]=a[mid].sd;
                num=a[mid].sd;
                i+=2;
            }
        }

        for(i=1; i<=n; i++)
        {
            if(i!=1)
                cout<<" ";
            cout<<b[i];
        }
        cout<<"\n";

    }
    return 0;
}


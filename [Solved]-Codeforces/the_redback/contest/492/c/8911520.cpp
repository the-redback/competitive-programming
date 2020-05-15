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

#define read(a)   scanf("%lld",&a)

pair<ll,ll>a[100010];

main()
{
    //freopen("C:\\Users\\Maruf\\Desktop\\in.txt","r",stdin);
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll t=1,tc;
    //cin>>tc;
    ll i,j,k,l,m,n;
    ll r,avg,cur;
    while(cin>>n>>r>>avg)
    {
        ll sum=0;
        ll ret=avg*n;
        for(i=0;i<n;i++)
        {
            cin>>k>>l;
            sum+=k;
            a[i].ft=l;
            a[i].sd=k;
        }
        sort(a,a+n);

//        cur=sum/n;
        ll cnt=0;

        for(i=0;i<n && sum<ret;i++)
        {
            ll rr=r-a[i].sd;
            ll tmp=ret-sum;
            ll temp=min(rr,tmp);
            sum+=temp;
            cnt+=temp*a[i].ft;
        }
        cout<<cnt<<"\n";

    }
    return 0;
}


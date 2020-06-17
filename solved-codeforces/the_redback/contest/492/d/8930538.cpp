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
#define inf       1e11
#define eps       1e-9
#define mod       1000000007
#define NN        30100

#define read(a)   scanf("%lld",&a)

pair<double,ll>a[2000010];


main()
{
    //freopen("C:\\Users\\Maruf\\Desktop\\in.txt","r",stdin);
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll t=1,tc;
    //cin>>tc;
    ll i,j,k,l,m,n;
    ll r,avg,cur;
    ll x,y;
    while(cin>>n>>x>>y)
    {
        ll sum=0;
        //ll ret=avg*n;
        j=0;
        for(i=1;i<=x || i<=y;i++)
        {
            if(i<=x)
            {
                double temp=i/(double)x;
                a[j].ft=temp;
                a[j].sd=1;
                //cout<<i<<" "<<j<<" "<<a[j].ft<<"\n";
                j++;
            }
            if(i<=y)
            {
                double temp=i/(double)y;
                a[j].ft=temp;
                a[j].sd=2;
                //cout<<i<<" "<<j<<" "<<a[j].ft<<"\n";
                j++;
            }
        }
        m=j;
        sort(a,a+m);
        ll last=-1;

        for(i=0;i<n;i++)
        {
            cin>>k;
            k--;
            ll now=k%m;
            if(now+1<m && a[now].ft==a[now+1].ft || now-1>=0 && a[now].ft==a[now-1].ft )
            {
                cout<<"Both\n";
                continue;
            }
            if(a[now].sd==1)
                cout<<"Vanya\n";
            else
                cout<<"Vova\n";
        }
    }
    return 0;
}


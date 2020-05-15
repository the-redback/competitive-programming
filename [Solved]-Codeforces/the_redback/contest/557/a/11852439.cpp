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
    //read(tc);
    ll i,j,k,l,m,n;
    while(cin>>n)
    {
        ll mx1,mx2,mx3,mn1,mn2,mn3;
        cin>>mn1>>mx1;
        cin>>mn2>>mx2;
        cin>>mn3>>mx3;

        ll sum1=0,sum2=0,sum3=0;

        sum3=max(mn3,n-(mx1+mx2));
        n-=sum3;

        sum2=max(mn2,(n-mx1));
        n-=sum2;

        sum1=n;

        cout<<sum1<<" "<<sum2<<" "<<sum3<<"\n";

    }
    return 0;
}

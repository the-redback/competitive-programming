/**
 *    @author     : Maruf Tuhin
 *    @School     : CUET CSE 11
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
#define meminf(a) memset(a,126,sizeof(a))
#define inf       1e11
#define eps       1e-9
#define mod       1000000007
#define NN        500100

//cout << setfill('0') << setw(3) << a << endl;
//cout << fixed << setprecision(20) << a << endl;

ll a[NN];

main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t=1,tc;
    ll i,j,k,l,m,n;
    ll a,b;
    cin>>n;
    cin>>a>>b;
    if(a*b>=n*6)
    {
        cout<<a*b<<"\n";
        cout<<a<<" "<<b<<"\n";
        return 0;
    }
    ll temp=n*6;
    ll ret=inf;
    ll f1=0,f2=0;
    ll fl=-1;
    if(a>b)
    {
        swap(a,b);
        fl=1;
    }
    for(i=a;i*i<=temp;i++)
    {
        ll tmp=ceil(temp/(double)i);
        if(tmp*i>temp && tmp*i<ret && tmp>=b)
        {
            ret=min(ret,tmp*i);
            f1=i;
            f2=tmp;
        }
        if(tmp*i==temp && tmp>=b)
        {
            f1=i;
            f2=tmp;
            ret=temp;
            break;
        }
    }
    if(fl==1)
        swap(f1,f2);
    cout<<ret<<"\n";
    cout<<f1<<" "<<f2<<"\n";

    return 0;
}

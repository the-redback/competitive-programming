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
//#define NN        30100

//cout << setfill('0') << setw(3) << a << endl;
//cout << fixed << setprecision(20) << a << endl;
#define NN 1000000
bool p[NN+7]; //Hashing
void sieve(void)
{
    ll n=NN;
    ll i,j,k,l;
    p[1]=1;
    for(i=4;i<=n;i+=2)
        p[i]=1;
    for(i=3;i*i<=n;i+=2)
    {
        if(p[i]==0)
        {
            for(j=i*i;j<=n;j+=2*i)
                p[j]=1;
        }
    }
}

main()
{
    sieve();
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t=1,tc;
    //cin>>tc;
    ll i,j,k,l,m,n;
    cin>>n;
    for(i=4;i<n;i++)
    {
        if(p[i]==0)
            continue;
        j=n-i;
        if(p[j]==0)
            continue;
        break;
    }
    cout<<i<<" "<<j<<"\n";

    return 0;
}

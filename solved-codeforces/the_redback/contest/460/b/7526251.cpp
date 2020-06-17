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

typedef long long          LL;
typedef unsigned long long LLU;

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
#define NN        1000000000

//cout << setfill('0') << setw(3) << a << endl;
//cout << fixed << setprecision(20) << a << endl;

LL check(LL n)
{
    LL sum=0;
    while(n>0)
    {
        sum+=n%10;
        n/=10;
    }
    return sum;
}

LL power(LL n,LL m)
{
    LL sum=1;
    while(m>0)
    {
        sum*=n;
        m--;
    }
    return sum;
}


main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t=1,tc;
    LL i,j,k,l,m,n,res,ret;
    LL a,b,c;
    cin>>a>>b>>c;

    vector<LL>v;
    v.clear();

    for(i=1;i<=81;i++)
    {
        res=power(i,a);
        ret=(res*b)+c;
        LL sum=check(ret);
        if(sum==i && ret>0 && ret<NN)
            v.pb(ret);
    }
    n=v.size();
    cout<<n<<"\n";
    for(i=0;i<v.size();i++)
    {
        if(i!=0)
            cout<<" ";
        cout<<v[i];
    }
    cout<<"\n";
    return 0;
}

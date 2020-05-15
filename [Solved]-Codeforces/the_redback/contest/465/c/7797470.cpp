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

string s;
ll N,p;

bool rec(ll pos,ll flag)
{
    if(pos==N)
        return flag;
    char i;
    if(flag==0)
        i=s[pos];
    else
        i='a';
    for(;i<'a'+p;i++)
    {
        if(pos>0 && s[pos-1]==i)
            continue;
        if(pos>1 && s[pos-2]==i)
            continue;
        if(s[pos]==i)
        {
            if(rec(pos+1,flag))
                return 1;
        }
        else
        {
            s[pos]=i;
            if(rec(pos+1,1))
                return 1;
        }
    }
    return 0;
}

main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t=1,tc;
    ll i,j,k,l,m,n;
    ll a,b;
    cin>>N>>p;
    cin>>s;
    if(rec(0,0))
        cout<<s<<"\n";
    else
        cout<<"NO\n";

    return 0;
}

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
#define NN        100210

//cout << setfill('0') << setw(3) << a << endl;
//cout << fixed << setprecision(20) << a << endl;

ll b[500];


string s;

main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    int t=1,tc;

    ll i,j,k,l,m,n,ii,jj;
    cin>>n>>k;
    cin>>s;
    mem(b,0);
    for(i=0;i<s.size();i++)
    {
        b[s[i]]++;
    }
    ll mx=0,res=k,ret=0,id;
    int fl=1;
    while(1)
    {
        mx=0;
        for(j='A';j<='Z';j++)
        {
            if(mx<b[j])
            {
                mx=max(b[j],mx);
                id=j;
            }
        }
        if(mx==0)
            break;
        b[id]=0;
        mx=min(mx,res);
        ret+=mx*mx;
        res-=mx;
        if(mx==0)
            break;
    }
    cout<<ret<<endl;
    return 0;
}

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


vector<ll>v;

main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    #ifdef redback
        freopen("C:\\Users\\Maruf\\Desktop\\in.txt","r",stdin);
    #endif

    ll t=1,tc;
    //read(tc);
    ll i,j,k,l,m,n;
    string s;
    while(cin>>n)
    {
        string s;
        v.clear();
        cin>>s;

        for(i=0;i<s.size();i++)
        {
            if(s[i]<='1')
                continue;
            if(s[i]=='2' || s[i]=='3' || s[i]=='5' || s[i]=='7')
            {
                v.pb(s[i]-'0');
            }
            else if(s[i]=='4')
            {
                v.pb(2);
                v.pb(2);
                v.pb(3);
            }
            else if(s[i]=='6')
            {
                v.pb(3);
                v.pb(5);
            }
            else if(s[i]=='8')
            {
                v.pb(2);
                v.pb(2);
                v.pb(2);
                v.pb(7);
            }
            else if(s[i]=='9')
            {
                v.pb(2);
                v.pb(3);
                v.pb(3);
                v.pb(7);
            }
        }
        sort(allr(v));
        for(i=0;i<v.size();i++)
        {
            cout<<v[i];
        }
        cout<<"\n";

    }
    return 0;
}
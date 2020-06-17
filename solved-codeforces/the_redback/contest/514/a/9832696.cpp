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




main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
#ifdef redback
    //freopen("C:\\Users\\Maruf\\Desktop\\in.txt","r",stdin);
#endif

    string s;

    ll t=1,tc;
    //read(tc);
    ll i,j,k,l,m,n;
    while(cin>>s)
    {
        for(i=0; i<s.size(); i++)
        {
            if('9'-s[i]>0 || i!=0)
            {
                ll mn=min(s[i]-'0','9'-s[i]);
                s[i]=(char)mn+'0';
            }
        }
        cout<<s<<"\n";
    }
    return 0;
}


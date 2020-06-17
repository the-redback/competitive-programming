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

string ss="CODEFORCES";
string s;

int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
#ifdef redback
    freopen("C:\\Users\\Maruf\\Desktop\\in.txt","r",stdin);
#endif

    ll t=1,tc;
    //read(tc);
    ll i,j,k,l,m,n;
    ll fl=0;
    while(cin>>s)
    {
        ll mx1=0;
        ll mx2=0,i;

        for(j=0, i=0; i<s.size() && j<ss.size(); i++,j++)
        {
            if(s[i]==ss[j])
            {
                mx1=max(mx1,j+1);
            }
            else
                break;
        }


        for(j=ss.size()-1,i=s.size()-1; i>=0 && j>=0; i--,j--)
        {
            if(s[i]==ss[j])
            {
                k=10-j;
                mx2=max(mx2,k);
            }
            else
                break;
        }

        if(mx1+mx2>=10)
            cout<<"YES\n";
        else
            cout<<"NO\n";

    }
    return 0;
}

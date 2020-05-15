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
#define NN        500000

#define read(n)   scanf("%lld",&n)

char a[NN];
int b[200];

main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    int t=1,tc;
    //cin>>tc;
    ll i,j,k,l,m,n;
    while(~read(n))
    {
        mem(b,0);
        scanf("%s",&a);

        l=strlen(a);
        ll ans=0;

        for(i=0,j=1;j<l;j+=2,i+=2)
        {
            char ch=tolower(a[j]);
            if(ch!=a[i])
            {
                if(b[ch]>0)
                {
                    b[ch]--;
                }
                else
                {
                    ans++;
                }
                b[a[i]]++;
            }
        }
        cout<<ans<<"\n";

    }
    return 0;
}

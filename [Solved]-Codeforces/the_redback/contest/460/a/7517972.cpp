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
#define NN        1010

//cout << setfill('0') << setw(3) << a << endl;
//cout << fixed << setprecision(20) << a << endl;


main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t=1,tc;
    LL i,j,k,l,m,n,res,ret;

    while(cin>>n>>m)
    {
        ret=0;
        res=n;
        for(i=1;i<=res;i++)
        {
            ret++;
            if(i%m==0)
                res++;
        }
        cout<<ret<<"\n";
    }
    return 0;
}

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

bool view[NN];


main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t=1,tc;
    //cin>>tc;
    ll i,j,k,l,m,n;
    while(cin>>n>>k)
    {
        mem(view,0);
        int fl=0;
        cout<<"1";
        view[1]=1;
        ll last=1,now;
        while(k>0)
        {
            if(fl==0)
            {
                last=last+k;
                k--;
                fl=1;
                view[last]=1;
                cout<<" "<<last;
            }
            else if(fl==1)
            {
                last=last-k;
                k--;
                fl=0;
                view[last]=1;
                cout<<" "<<last;
            }
        }
        for(i=1;i<=n;i++)
        {
            if(view[i]==0)
                cout<<" "<<i;
        }
        cout<<"\n";
        return 0;
    }
    return 0;
}

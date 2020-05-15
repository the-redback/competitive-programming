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


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifdef redback
        freopen("C:\\Users\\Maruf\\Desktop\\in.txt","r",stdin);
    #endif

    ll t=1,tc;
    //read(tc);
    ll i,j,k,l,m,n;
    while(cin>>n)
    {
        cin>>m;
        ll retLast=0,sum=0,last=0;
        while(m--)
        {
            ll fl=0;
            cin>>k;
            sum+=k-1;
            for(i=0;i<k;i++)
            {
                cin>>l;
                if(fl==1)
                {
                    if(last+1==l)
                        last++;
                    else
                        fl=0;
                }
                else if(l==1)
                {
                    last=1;
                    fl=1;
                }
            }
        }
        sum-=last-1;
        sum+=n-last;
        cout<<sum<<"\n";

    }
    return 0;
}

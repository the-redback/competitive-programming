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

ll a[50];
ll L,R,X,N;
ll viw[50];

ll rec(ll pos)
{
    if(pos==N)
    {
        ll sum=0,mn=inf,mx=-inf;
        ll i;
        for(i=0;i<N;i++)
        {
            if(viw[i])
            {
                sum+=a[i];
                mn=min(mn,a[i]);
                mx=max(mx,a[i]);
            }
        }
        if(sum>=L && sum<=R && mx-mn>=X)
            return 1;
        return 0;
    }

    ll ret=0;
    ret=rec(pos+1);

    viw[pos]=1;
    ret+=rec(pos+1);
    viw[pos]=0;

    return ret;
}


int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    #ifdef redback
        freopen("C:\\Users\\Maruf\\Desktop\\in.txt","r",stdin);
    #endif

    ll t=1,tc;
    //read(tc);
    ll i,j,k,l,m,n;
    while(~read(N))
    {
        read(L);
        read(R);
        read(X);
        for(i=0;i<N;i++)
            read(a[i]);
        ll ret=0;
        mem(viw,0);

        ret=rec(0);

        printf("%lld\n",ret);

    }
    return 0;
}

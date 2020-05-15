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
#define NN        100

#define read(a)   scanf("%lld",&a)

ll hor[NN];
ll ver[NN];


int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    #ifdef redback
        freopen("C:\\Users\\Maruf\\Desktop\\in.txt","r",stdin);
    #endif

    ll t=1,tc;
    //read(tc);
    ll i,j,k,l,m,n;
    while(~read(n))
    {
        mem(hor,-1);
        mem(ver,-1);

        ll ans=0;

        for(i=1;i<=n*n;i++)
        {
            read(k);
            read(l);
            if(hor[k]==-1 && ver[l]==-1)
            {
                ans++;
                hor[k]=1;
                ver[l]=1;

                if(i!=1)
                    printf(" ");
                printf("%lld",i);
            }
        }
        printf("\n");

    }
    return 0;
}

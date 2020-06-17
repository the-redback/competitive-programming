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

vector<pair<ll,ll> >v;
ll a[NN],b[10];

int main()
{
    #ifdef redback
        freopen("C:\\Users\\Maruf\\Desktop\\in.txt","r",stdin);
    #endif

    ll t=1,tc;
    //read(tc);
    ll i,j,k,l,m,n;
    while(~read(n))
    {
        for(i=0;i<n;i++)
        {
            read(a[i]);
        }

        v.clear();

        for(i=0;i<5;i++)
        {
            read(k);
            v.pb(mp(k,i));
        }
        ll fl=0;
        sort(allr(v));
        mem(b,0);

        k=0;

        for(i=0;i<n;i++)
        {
            k+=a[i];
            fl=0;
            while(k>0)
            {
                fl=0;
                for(j=0;j<5;j++)
                {
                    if(v[j].ft<=k)
                    {
                        l=k/v[j].ft;
                        b[v[j].sd]+=l;
                        k-=v[j].ft*l;
                        fl=1;
                        break;
                    }
                }
                if(!fl)
                    break;
            }
        }

        for(i=0;i<5;i++)
        {
            if(i!=0)
                printf(" ");
            printf("%lld",b[i]);
        }
        printf("\n%lld\n",k);


    }
    return 0;
}

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

ll a[NN];

int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    #ifdef redback
        freopen("C:\\Users\\Maruf\\Desktop\\in.txt","r",stdin);
    #endif

    ll t=1,tc;
    //read(tc);
    ll i,j,k,l,m,n;
    while(cin>>n)
    {

        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }
        for(i=0;i<n;i++)
        {
            if(a[i]==1)
            {
                k=i;
                break;
            }
        }
        if(i==n)
        {
            printf("0\n");
            continue;
        }
        for(i=n-1;i>=0;i--)
        {
            if(a[i]==1)
            {
                l=i;
                break;
            }
        }

        ll flag=0,sum=0;

        for(i=k;i<=l;i++)
        {
            if(a[i]==1)
            {
                sum++;
                if(flag>0 && flag<2)
                    sum++;
                flag=0;
            }
            else
            {
                flag++;
            }
        }
        printf("%lld\n",sum);

    }
    return 0;
}

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

ll a[20]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
ll b[500];

ll power(ll n,ll m)
{
    ll sum=1;
    for(ll i=1;i<=m;i++)
        sum*=n;
    return sum;

}

main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    #ifdef redback
       // freopen("C:\\Users\\Maruf\\Desktop\\in.txt","r",stdin);
    #endif

    ll t=1,tc;
    //read(tc);
    ll i,j,k,l,m,n;
    while(cin>>n>>m)
    {
        ll total=power(2,n-1);
        mem(b,-1);
        ll sum=0;
        j=1;
        ll jj=0;
        for(i=n-2;i>=-1;i--)
        {
            k=power(2,i);
            if(m<=k)
            {
                if(jj!=0)
                    cout<<" ";
                cout<<j;
                b[j]=1;
                jj++;
            }
            else
            {
                sum+=k;
                m-=k;
            }
            j++;
        }
        for(i=n;i>=1;i--)
        {

            jj++;
            if(b[i]==-1)
            {
                if(jj!=0)
                    cout<<" ";
                cout<<i;
            }

        }
        cout<<"\n";



    }
    return 0;
}



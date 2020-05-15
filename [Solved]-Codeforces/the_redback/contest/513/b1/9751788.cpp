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
ll b[50000];

ll N;

ll check(void)
{
    ll n=N,mn;
    ll sum=0;
    for(ll i=0;i<n;i++)
    {
        mn=inf;
        for(ll j=i;j<n;j++)
        {
            mn=min(mn,a[j]);
            sum+=mn;
        }
    }
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
        N=n;
        i=0;
        ll mx=0;
        mem(b,0);

        sort(a,a+n);
        do
        {
            i++;
            b[i]=check();
            mx=max(b[i],mx);
        }while(next_permutation(a,a+n));
        k=i;
        j=0;

        for(i=0;i<=k;i++)
        {
            if(b[i]==mx)
            {
                j++;
            }
            if(j==m)
                break;
        }
        k=i;
        i=0;
        sort(a,a+n);
        do
        {
            i++;
            if(i==k)
            {
                break;
            }
        }while(next_permutation(a,a+n));

        for(i=0;i<n;i++)
        {
            if(i!=0)
                cout<<" ";
            cout<<a[i];
        }
        cout<<"\n";



    }
    return 0;
}


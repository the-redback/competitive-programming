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

vector<ll>ans;

bool isprime(ll n)
{
    if(n==2)
        return 1;
    if(n==1 || n%2==0)
        return 0;
    for(ll i=3;i*i<=n;i+=2)
        if(n%i==0)
            return 0;
    return 1;
}

ll check(ll n)
{
    if(isprime(n))
    {
        ans.pb(n);
        return 1;
    }
    for(ll i=n;i>=2;i--)
    {
        if(isprime(i) && isprime(n-i))
        {
            ans.pb(i);
            ans.pb(n-i);
            return 1;
        }
    }
    return 0;
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
    while(cin>>n)
    {
        ans.clear();
        if(isprime(n))
        {
            printf("1\n%lld\n",n);
            return 0;
        }
        for(i=n;i>=2;i-=2)
        {
            if(isprime(i))
            {
                ans.pb(i);
                if(check(n-i))
                {
                    printf("%lld\n",(ll)ans.size());
                    for(j=0;j<ans.size();j++)
                        printf("%lld ",ans[j]);
                    return 0;
                }
            }
        }

    }
    return 0;
}

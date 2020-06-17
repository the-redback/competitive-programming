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

char a[10000];

int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
#ifdef redback
    //freopen("C:\\Users\\Maruf\\Desktop\\in.txt","r",stdin);
#endif

    ll t=1,tc;
    //read(tc);
    ll i,j,k,l,m,n;
    while(~scanf("%d %s",&n,&a))
    {
        ll cnt=0;
        n=strlen(a);
        for(i=1; i<=n; i++)
        {
            cnt=0;
            for(j=0; j<n; j++)
            {
                k=j;
                cnt=0;
                while(k<n)
                {
                    if(a[k]=='.')
                    {
                        cnt=-1;
                        break;
                    }
                    cnt++;
                    k+=i;
                    if(cnt==5)
                        break;
                }
                if(cnt==5)
                {
                    puts("yes");
                    return 0;
                }

            }
        }
        puts("no");

    }
    return 0;
}

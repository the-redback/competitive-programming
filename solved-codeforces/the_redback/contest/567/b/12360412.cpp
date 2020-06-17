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
#define NN        1000010

#define read(a)   scanf("%lld",&a)

ll a[NN];
char s[10];

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
        mem(a,0);
        ll sum=0,cur=0;
        for(i=0;i<n;i++)
        {
            scanf("%s %lld",&s,&k);
            if(s[0]=='-')
            {
                if(a[k]!=-1)
                    sum++;
                else
                {
                    a[k]=0;
                    cur--;
                }
            }
            else
            {
                a[k]=-1;
                cur++;
            }
            sum=max(sum,cur);
        }
        printf("%lld\n",sum);

    }
    return 0;
}

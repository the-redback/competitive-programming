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

char a[NN];

ll checkab(ll k)
{
    ll i,j,l;
    l=strlen(a);

    for(i=0;i<l-1;i++)
    {
        if(i==k ||i==k+1 || i+1==k)
        {
            continue;
        }
        if(a[i]=='A' && a[i+1]=='B')
        {
            return 1;
        }
    }
    return 0;
}

ll checkba(ll k)
{
    ll i,j,l;
    l=strlen(a);

    for(i=0;i<l-1;i++)
    {
        if(i==k ||i==k+1 || i+1==k)
        {
            continue;
        }
        if(a[i]=='B' && a[i+1]=='A')
        {
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
    while(~scanf("%s",&a))
    {
        l=strlen(a);
        ll flag=-1;

        ll ina,inb;

        ll ab=0,ba=0;

        for(i=0;i<l-1;i++)
        {
            if(a[i]=='A' && a[i+1]=='B')
            {
                ab++;
                ina=i;
            }
        }

        for(i=0;i<l-1;i++)
        {
            if(a[i]=='B' && a[i+1]=='A')
            {
                ba++;
                inb=i;
            }
        }

        if(ab>1 && ba>1)
            flag=1;
        else
        {
            if(ab==1 && checkba(ina))
            {
                flag=1;
            }
            if(ba==1 && checkab(inb))
            {
                flag=1;

            }
        }

        if(flag==1)
        {
            printf("YES\n");
        }
        else
            printf("NO\n");


    }
    return 0;
}

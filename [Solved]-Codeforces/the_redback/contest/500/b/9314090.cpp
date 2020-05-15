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
#define NN        305

#define read(a)   scanf("%lld",&a)

ll d[NN][NN];
char aa[NN][NN];
ll a[NN];

main()
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
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }
        for(i=0;i<n;i++)
            scanf("%s",&aa[i]);
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                d[i][j]=aa[i][j]-'0';
        for(k=0;k<n;k++)
            for(i=0;i<n;i++)
                for(j=0;j<n;j++)
                    d[i][j]=d[i][j]|| (d[i][k] && d[k][j]);
        ll last=n-1;
        ll fl=-1;
        while(last>=0)
        {
            fl=-1;
            for(j=0;j<n;j++)
            {
                if(a[last]<a[j] && d[last][j] && last>j)
                {
                    swap(a[last],a[j]);
                    fl=0;
                    break;
                }
            }
            if(fl==0)
                last=n-1;
            else
                last=last-1;
        }
        for(i=0;i<n;i++)
        {
            if(i!=0)
                printf(" ");
            printf("%lld",a[i]);
        }
        puts("");

    }
    return 0;
}


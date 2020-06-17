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
#define NN        1010

#define read(a)   scanf("%lld",&a)

char a[1010][1010];
char b[1010][1010];
ll fl[NN];
ll bl[NN];

main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    #ifdef redback
        //freopen("C:\\Users\\Maruf\\Desktop\\in.txt","r",stdin);
    #endif

    ll t=1,tc;
    //read(tc);
    ll i,j,k,l,m,n;
    while(~read(n))
    {
        read(m);
        for(i=0;i<n;i++)
            scanf("%s",&a[i]);
        mem(fl,-1);
        mem(bl,-1);
        ll cnt=0;

        for(j=0;j<m;j++)
        {
            ll flag=0;
            for(i=1;i<n;i++)
            {
                if(a[i][j]<a[i-1][j])
                {
                    if(bl[i]!=0)
                    {
                        fl[j]=0;
                        break;
                    }
                }
            }
            if(fl[j])
            for(i=1;i<n;i++)
            {
                if(a[i][j]==a[i-1][j])
                {
                    if(bl[i]==-1)
                        bl[i]=1;
                    else if(bl[i]==0 || bl[i]==1)
                        continue;
                }
                else if(a[i][j]>a[i-1][j])
                {
                    bl[i]=0;
                }
                else if(a[i][j]<a[i-1][j])
                {
                    if(bl[i]==0)
                        continue;
                    else
                    {
                        fl[j]=0;
                    }
                }
            }
        }
        for(i=0;i<m;i++)
            if(fl[i]==0)
            cnt++;
        printf("%lld\n",cnt);


    }
    return 0;
}


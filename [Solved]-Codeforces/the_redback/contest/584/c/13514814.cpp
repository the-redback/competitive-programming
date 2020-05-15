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
char b[NN];
char c[NN];

ll flag[NN];

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
        read(m);

        scanf("%s",&a);
        scanf("%s",&b);
        mem(flag,-1);

        ll sum=0,sum1=0;
        for(i=0;i<n;i++)
        {
            if(a[i]!=b[i])
                sum++;
            else
                c[i]=a[i];
        }

        sum1=sum;

        ll tmp=ceil(sum/2.0);

        if(tmp>m)
        {
            printf("-1\n");
            continue;
        }

        ll flg=0,in=-1;

        for(i=0;i<n;i++)
        {
            if(a[i]!=b[i])
            {
                if(flg==0)
                    c[i]=a[i];
                else
                    c[i]=b[i];
                flag[i]=flg;
                in=i;
                if(flg==1)
                    m--;
                flg++;
                flg%=2;
            }
        }

        if(sum%2==1)
        {
            flag[in]=2;
            for(j='a';j<='z';j++)
                if(a[in]!=j && b[in]!=j)
                {
                    c[in]=j;
                    break;
                }
            m--;
        }

        for(i=0;i<n && m>0;i++)
        {
            if(a[i]==b[i])
            {
                c[i]=a[i]+1;
                if(c[i]>'z')
                    c[i]='a';
                m--;
            }
        }

        for(i=0;i<n && m>0;i++)
        {
            if(flag[i]==0 || flag[i]==1)
            {
                for(j='a';j<='z';j++)
                    if(a[i]!=j && b[i]!=j)
                    {
                        c[i]=j;
                        break;
                    }
            }
            if(flag[i]==1)
                m--;
        }
        c[n]=0;
        puts(c);

    }
    return 0;
}

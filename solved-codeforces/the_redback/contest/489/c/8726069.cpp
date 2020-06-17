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
#define NN        30100

//#define read(a)   scanf("%lld",&a)

ll a[200];
ll b[200];

main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t=1,tc;
    //cin>>tc;
    ll i,j,k,l,m,n;
    while(cin>>n>>m)
    {
        if(m==0 && n==1)
        {
            cout<<"0 0\n";
            return 0;
        }
        if(m==0 && n>1)
        {
            cout<<"-1 -1\n";
            return 0;
        }
        else
        {
            /*
            if(s==1)
            {
                a[0]=1;
                b[0]=1;
                for(i=1;i<n;i++)
                {
                    a[i]=1;

                }
            }*/
            ll sum=0;
            for(i=1;i<=n;i++)
            {
                for(j=9;j>=0;j--)
                {
                    if(sum+j+0<=m)
                    {
                        a[i]=j;
                        sum+=j;
                        break;
                    }
                }
            }

            if(sum!=m)
            {
                cout<<"-1 -1\n";
                return 0;
            }
            sum=0;
            for(i=n;i>=1;i--)
            {
                for(j=9;j>=0;j--)
                {
                    if(sum+j+1<=m|| i==1 && sum+j==m)
                    {
                        b[i]=j;
                        sum+=j;
                        break;
                    }
                }
            }
            if(sum!=m)
            {
                cout<<"-1 -1\n";
                return 0;
            }
            for(i=1;i<=n;i++)
                cout<<b[i];
            cout<<" ";
            for(j=1;j<=n;j++)
                cout<<a[j];
            cout<<"\n";

        }
        return 0;

    }
    return 0;
}


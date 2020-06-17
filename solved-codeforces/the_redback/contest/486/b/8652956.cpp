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

ll a[111][111];
ll b[111][111];

int N,M;

void Set(int r,int c)
{
    int i,j;
    for(i=0;i<N;i++)
        a[r][i]=0;
    for(i=0;i<M;i++)
        a[i][c]=0;
    return;
}

ll check(int r,int c,int val)
{
    int i,j;
    bool flag=0;
    for(i=0;i<N;i++)
        flag |=a[r][i];
    for(i=0;i<M;i++)
        flag |=a[i][c];
    if(flag==val)
        return 1;
    else
        return 0;
}


main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t=1,tc;
    //cin>>tc;
    ll i,j,k,l,m,n;
    cin>>M>>N;

    for(i=0;i<M;i++)
    {
        for(j=0;j<N;j++)
        {
            a[i][j]=1;
        }
    }

    for(i=0;i<M;i++)
    {
        for(j=0;j<N;j++)
        {
            cin>>b[i][j];
            if(b[i][j]==0)
                Set(i,j);
        }
    }

    for(i=0;i<M;i++)
    {
        for(j=0;j<N;j++)
        {
            if(!check(i,j,b[i][j]))
            {
                cout<<"NO\n";
                return 0;
            }
        }
    }
    cout<<"YES\n";
    for(i=0;i<M;i++)
    {
        for(j=0;j<N;j++)
        {
            if(j!=0)
                cout<<" ";
            cout<<a[i][j];
        }
        cout<<"\n";
    }


    return 0;
}

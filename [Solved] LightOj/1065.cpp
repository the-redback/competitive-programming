/**
 *    @author     : Maruf Tuhin
 *    @School     : CUET CSE 11
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
#define meminf(a) memset(a,126,sizeof(a))
#define inf       1e11
#define eps       1e-9
#define mod       1000000007
#define NN        30100

//cout << setfill('0') << setw(3) << a << endl;
//cout << fixed << setprecision(20) << a << endl;

/*
   |1 1|^k * |f(1)| = |f(k+1)|
   |1 0|     |f(0)|   | f(k) |
   here,
   f(0)=aa;
   f(1)=bb;
*/

ll M;

ll m[3][3];

void mult(ll a[3][3],ll b[3][3])
{
    ll temp[3][3];
    int i,j,k;
    mem(temp,0);
    for(i=0;i<2;i++)
            for(j=0;j<2;j++)
                for(k=0;k<2;k++)
                    temp[i][j]+=a[i][k]*b[k][j];
    for(i=0;i<2;i++)
        for(j=0;j<2;j++)
            a[i][j]=temp[i][j]%M;
    return;
}

void BigMat(ll a[3][3],int pos)
{
    int i,j,k;
    if(pos==1)
        return;
    if(pos%2==1)
    {
        BigMat(a,pos-1);
        mult(a,m);
    }
    else
    {
        BigMat(a,pos/2);
        mult(a,a);
    }
    return;
}

main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t=1,tc;
    cin>>tc;
    ll i,j,k,l,n;
    ll aa,bb;
    while(tc--)
    {
        cin>>aa>>bb>>n>>M;
        if(n==0)
        {
            printf("Case %d: %lld\n",t++,aa);
            continue;
        }
        if(n==1)
        {
            printf("Case %d: %lld\n",t++,bb);
            continue;
        }

        ll a[3][3];
        a[0][0] = m[0][0]=1;
        a[0][1] = m[0][1]=1;
        a[1][0] = m[1][0]=1;
        a[1][1] = m[1][1]=0;

        if(M==1)
            M=10;
        else if(M==2)
            M=100;
        else if(M==3)
            M=1000;
        else if(M==4)
            M=10000;

        BigMat(a,n);

        m[0][0]=bb;
        m[1][0]=aa;
        ll temp[3][3];
        mem(temp,0);
        for(i=0;i<2;i++)
            for(j=0;j<1;j++)
                for(k=0;k<2;k++)
                    temp[i][j]+=a[i][k]*m[k][j];
        printf("Case %d: %lld\n",t++,temp[1][0]%M);
    }
    return 0;
}

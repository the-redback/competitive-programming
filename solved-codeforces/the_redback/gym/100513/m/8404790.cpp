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

char a[60][200];

struct D
{
    char ch;
    int r,c;
    D(char CH,int R,int C)
    {
        ch=CH,r=R,c=C;
    }
    D()
    {

    }
} ar[4000];

stack<D>q;


main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    int t=1,tc;
    //cin>>tc;
    int i,j,k,l,m,n;
    scanf("%d",&n);
    getchar();
    for(i=0; i<n; i++)
    {
        gets(a[i]);
    }
    int bb=0,N=0;
    ar[0]=D('{',0,0);
    for(i=0; i<n; i++)
    {
        l=strlen(a[i]);
        for(j=0; j<l; j++)
        {
            if(a[i][j]!=' ')
            {
                ar[N]=D(a[i][j],i,j);
                N++;
            }
        }
    }
    for(i=0; i<N; i++)
    {
        bb=0;
        q=stack<D>();
        for(j=0; j<i; j++)
        {
            if(ar[j].ch=='}')
            {
                while(q.size())
                {
                    D ad=q.top();
                    q.pop();
                    if(ad.ch=='{')
                        break;
                }
            }
            else
                q.push(ar[j]);
        }
        int fl=0;
        while(q.size())
        {
            D ad=q.top();
            q.pop();
            if(ad.ch=='{')
                fl=1;
            if(ad.ch>='a' && ad.ch<='z' && ad.ch==ar[i].ch && fl==1)
            {
                printf("%d:%d: warning: shadowed declaration of %c, the shadowed position is %d:%d\n",ar[i].r+1,ar[i].c+1,ar[i].ch,ad.r+1,ad.c+1);
                break;
            }
        }

    }


    return 0;
}

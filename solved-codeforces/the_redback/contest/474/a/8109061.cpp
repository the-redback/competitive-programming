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

char a[5][20]= {"qwertyuiop",
                "asdfghjkl;",
                "zxcvbnm,./"
               };

char b[200];
char s[10];

main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    int t=1,tc;
    //cin>>tc;
    ll i,j,k,l,m,n;
    while(~scanf("%s",&s))
    {
        scanf("%s",&b);
        ll r=strlen(b);
        for(k=0; k<r; k++)
        {
            int fl=1;
            for(i=0; i<3 && fl; i++)
            {
                l=strlen(a[i]);
                for(j=0; j<l && fl; j++)
                {
                    if(s[0]=='R' && b[k]==a[i][j] && j!=0)
                    {
                        b[k]=a[i][j-1];
                        fl=0;
                    }
                    else if(s[0]=='L' && b[k]==a[i][j] && j!=l-1)
                    {
                        b[k]=a[i][j+1];
                        fl=0;
                    }
                }
            }
        }
        puts(b);


    }
    return 0;
}


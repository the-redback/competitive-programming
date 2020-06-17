/**
 *    @author     : Maruf Tuhin
 *    @School     : CUET CSE 11
 *    @TOPCODER   : the_redback
 *    @CodeForces : the_redback
 *    @UVA        : the_redback
 *    @link       : http://www.fb.com/maruf.2hin
 */

#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<set>
#include<sstream>
#include<stack>
using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define pp pop_back
#define inf 10e9 //10^9
#define meminf 100
#define eps 10e-5
#define NN 1000000

main()
{
    ios_base::sync_with_stdio(false);
    int t=1,tc;
    int i,j,k,l,m,n;
    int x,y,z,u,w,xx,yy,zz,d,h;
    int aa,bb,cc,p,dd;
    cin>>tc;
    while(tc--)
    {
        cin>>n>>p;
        int fl=1;
        l=2*n+p;
        for(i=1;i<=n && fl;i++)
        {
            for(j=i+1;j<=n && fl;j++)
            {
                if(l)
                {
                    printf("%d %d\n",i,j);
                    l--;
                }
                else
                    fl=0;
            }
        }
    }
    return 0;
}

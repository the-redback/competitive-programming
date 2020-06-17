/**
 *    @author     : Maruf Tuhin
 *    @School     : CUET CSE 11
 *    @Topcoder   : the_redback
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
#define inf 10000000
#define NN 20
char a[NN];
vector<int>v;

main()
{
    int t,tc;
    int i,j,k,l,newx,newy,xx,yy,rr,r;
    int res,u,w,p,n,x,y,z,m,q,N,M;
    //cin>>tc;
    while(~scanf("%d%d%d%d%d%d",&N,&M,&x,&y,&z,&q))
    {
        x=x%4;
        y=y%2;
        z=z%4;
        while(q--)
        {
            scanf("%d%d",&xx,&yy);
            r=x;
            n=N;
            m=M;
            while(r--)
            {
                newx=yy;
                k=xx-1;
                newy=n-k;
                xx=newx;
                yy=newy;
                swap(n,m);
            }
            r=y;
            while(r--)
            {
                newx=xx;
                k=yy-1;
                newy=m-k;
                xx=newx;
                yy=newy;
            }
            r=z;
            while(r--)
            {
                newy=xx;
                k=yy-1;
                newx=m-k;
                xx=newx;
                yy=newy;
                swap(n,m);
            }
            printf("%d %d\n",xx,yy);
        }
    }
    return 0;
}

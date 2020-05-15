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

#define ft first
#define sd second
#define ll __int64
#define mp make_pair
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 1e9
#define eps 1e-9
#define NN 1050

int a[200010];

main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t,tc;
    //cin>>tc;
    int i,j,k,l,n,m;
    int x1,x2,x3,x4,y1,y2,y3,y4;

    while(cin>>n)
    {
        for(i=0;i<n;i++)
            cin>>a[i];
        sort(a,a+n);
        int res=a[n-1]-a[0];
        ll xx=0,yy=0;
        for(i=0;i<n;i++)
        {
            if(a[i]==a[0])
                xx++;
            else if(a[i]==a[n-1])
                yy++;
        }
        ll ret=xx*yy;
        if(res==0)
        {
            ll temp=max(xx,yy)-1;
            ret=(temp*(temp+1))/2.0;
        }

        printf("%d %I64d\n",res,ret);
    }
    return 0;
}

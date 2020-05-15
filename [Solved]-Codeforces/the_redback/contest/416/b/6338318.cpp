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

#define ppb pop_back
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 2000000000
#define eps 1e-9
#define NN 400010

__int64 a[50010][10];
//vector<int>v;
main()
{
    ios_base::sync_with_stdio(false);
    int t,tc;
    //cin>>tc;
    int n,m,i,j,k,l;
    __int64 r;
    int low,high;
    for(i=0;i<8;i++)
        a[0][i]=0;
    for(i=0;i<50005;i++)
        a[i][0]=0;
    while(cin>>m>>n)
    {
        //v.clear();
        for(i=1;i<=m;i++)
        {
            int total=0;
            for(j=1;j<=n;j++)
            {
                cin>>r;
                a[i][j]=max(a[i-1][j],a[i][j-1])+r;
            }
        }
        for(i=1;i<=m;i++)
        {
            if(i!=1)
                printf(" ");
            printf("%I64d",a[i][n]);
        }
        printf("\n");
    }
    return 0;
}

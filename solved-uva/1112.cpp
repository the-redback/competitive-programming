/**
 *    @author     : Maruf Tuhin
 *    @School     : CUET CSE 11
 *    @Topcoder   : the_redback
 *    @CodeForces : the_redback
 *    @UVA        : Redback
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

#define inf 10000000
#define mem(a,b) memset(a,b,sizeof(a))
#define NN 111
int pr[NN+7];
int a[NN+7][NN+7];

main()
{
    //freopen("C:\\Users\\Maruf Tuhin\\Desktop\\in.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    int i,j,k,l,n,r,c,count,time;
    int tc,t=1;
    int u,v,w;
    cin>>tc;
    while(tc--)
    {
        cin>>n>>r>>time;
        cin>>c;
        for(i=0;i<=n;i++)
        {
            for(j=0;j<=n;j++)
                a[i][j]=inf;
            a[i][i]=0;
        }
        while(c--)
        {
            cin>>u>>v>>w;
            a[u][v]=w;
        }
        for(k=1;k<=n;k++)
            for(i=1;i<=n;i++)
                for(j=1;j<=n;j++)
                    a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
        if(t!=1)
            cout<<"\n";
        t++;
        int sum=0;
        for(i=1;i<=n;i++)
            if(a[i][r]<=time)
                sum++;
        cout<<sum<<"\n";
    }
    return 0;
}







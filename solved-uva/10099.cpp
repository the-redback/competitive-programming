/**
 *                                   ____
 *       ____ ___  ____ ________  __/ __/
 *      / __ `__ \/ __ `/ ___/ / / / /_
 *     / / / / / / /_/ / /  / /_/ / __/
 *    /_/ /_/ /_/\__,_/_/   \__,_/_/
 *
 *    @link : https://the-redback.com
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
#define NN 100
int pr[NN+7];
int a[NN+7][NN+7];

main()
{
    //freopen("C:\\Users\\Maruf Tuhin\\Desktop\\in.txt","r",stdin);
    //ios_base::sync_with_stdio(false);
    int i,j,k,l,n,r,c,count;
    int tc,t=1;
    int u,v,w;
    //scanf("%d",&tc);
    while(~scanf("%d%d",&n,&r))
    {
        if(n==0 && r==0)
            return 0;
        for(i=0;i<=n;i++)
        {
            for(j=0;j<=n;j++)
                a[i][j]=-inf;
            a[i][i]=0;
        }
        while(r--)
        {
            scanf("%d%d%d",&u,&v,&w);
            a[u][v]=w;
            a[v][u]=w;
        }
        scanf("%d%d%d",&u,&v,&w);
        for(k=1;k<=n;k++)
            for(i=1;i<=n;i++)
                for(j=1;j<=n;j++)
                    a[i][j]=max(a[i][j],min(a[i][k],a[k][j]));
        int sum=a[u][v]-1;
        sum=ceil(w/(double)sum);
        printf("Scenario #%d\nMinimum Number of Trips = %d\n\n",t++,sum);
    }
    return 0;
}







/**
 *                                   ____
 *       ____ ___  ____ ________  __/ __/
 *      / __ `__ \/ __ `/ ___/ / / / /_
 *     / / / / / / /_/ / /  / /_/ / __/
 *    /_/ /_/ /_/\__,_/_/   \__,_/_/
 *
 *    @link : https://the-redback.com
 */
#include <bits/stdc++.h>
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







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

#define mem(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define pp pop_back
#define LL __int64
#define inf 10000000
#define NN 1010

char a[NN][NN];
int vis[NN];
int flg,N,M;

void check(int j)
{
    int res=0,g,s;
    for(int i=0;i<M;i++)
    {
        if(a[j][i]=='G')
            g=i;
        if(a[j][i]=='S')
            s=i;
    }
    if(s<g)
        flg=1;
    int k=abs(s-g);
    vis[k]=1;
    return;
}

main()
{
    int t,tc;
    int i,j,k,l;
    int u,w,p,x,y,z,m,q,cnt;
    //cin>>tc;
    while(~scanf("%d%d",&N,&M))
    {
        mem(vis,0);
        flg=0;
        cnt=0;
        for(i=0;i<N;i++)
        {
            scanf("%s",&a[i]);
            check(i);
        }
        for(i=0;i<=M;i++)
        {
            if(vis[i])
                cnt++;
        }
        if(flg)
            cnt=-1;
        printf("%d\n",cnt);


    }
    return 0;
}


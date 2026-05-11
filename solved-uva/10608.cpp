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
#define inf 10000000
#define NN 30000
int pr[NN+7];
int a[NN+7];
int cnt;
int root(int n)
{
    if(pr[n]==n)
        return n;
    return root(pr[n]);
}

main()
{
    int tc,t=1;
    int i,j,k,l,m,n,cnt1,cnt2,count;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d%d",&n,&m);
        for(i=0;i<=n;i++)
            pr[i]=i,a[i]=0;
        while(m--)
        {
            scanf("%d%d",&k,&l);
            int u=root(k);
            int v=root(l);
            if(u!=v)
            {
                pr[u]=v;
            }
        }
        count=0;
        for(i=1;i<=n;i++)
        {
            int u=root(i);
            a[u]++;
            count=max(count,a[u]);
        }
        printf("%d\n",count);
    }
}



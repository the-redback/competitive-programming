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



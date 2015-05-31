/**
 *    @author     : Maruf Tuhin
 *    @School     : CUET CSE 11
 *    @TOPCODER   : the_redback
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
#define NN 50000
int prnt[NN+7];
int a[NN+7];
int root(int n)
{
    if(prnt[n]==n)
        return n;
    return root(prnt[n]);
}

main()
{
    //freopen("C:\\Users\\Maruf Tuhin\\Desktop\\in.txt","r",stdin);
    //ios_base::sync_with_stdio(false);
    int i,j,k,l,n,r,c,count;
    int tc,t=1;
    //scanf("%d",&tc);
    while(~scanf("%d%d",&n,&r))
    {
        if(n==0 && r==0)
            return 0;
        for(i=1;i<=n;i++)
            prnt[i]=i;
        while(r--)
        {
            scanf("%d%d",&k,&l);
            int u=root(k);
            int v=root(l);
            if(u!=v)
                prnt[u]=v;
        }
        mem(a,0);
        count=0;
        for(i=1;i<=n;i++)
        {
            int u=root(i);
            if(a[u]==0)
                count++;
            a[u]=1;
        }
        printf("Case %d: %d\n",t++,count);
    }
    return 0;
}


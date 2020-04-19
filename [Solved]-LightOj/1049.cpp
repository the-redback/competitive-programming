/**
 *    @author     : Maruf Tuhin
 *    @School     : CUET CSE 11
 *    @TOPCODER   : the_redback
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
#define inf 1000000000
#define NN 100

int a[NN+7][NN+7];
int view[NN+7];
int N;
int call(int u)
{
    view[u]=1;
    int i,res=0;
    for(i=1;i<=N;i++)
    {
        if(a[u][i]!=-1 && view[i]==0)
        {
            res=a[u][i]+call(i);
        }
    }
    return res;
}

int main()
{
    int tc,t=1,res=0;
    int i,j,k,l,cc;
    int r[3];
    int n,m,x=0,y=0;
    int u,v,w;
    scanf("%d",&tc);
    while(tc--)
    {
        mem(a,-1);
        mem(view,0);
        scanf("%d",&n);
        j=0;
        N=n;
        for(i=0;i<n;i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            a[u][v]=0;
            a[v][u]=w;
            if(u==1)
                r[j++]=v;
            if(v==1)
                r[j++]=u;
        }
        cc=a[1][r[0]]+a[r[1]][1];
        view[1]=1;
        cc+=call(r[0]);
        res=cc;
        mem(view,0);
        view[1]=1;
        cc=a[1][r[1]]+a[r[0]][1];
        cc+=call(r[1]);
        res=min(res,cc);
        printf("Case %d: %d\n",t++,res);
    }
    return 0;
}

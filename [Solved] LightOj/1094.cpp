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
#define inf 999999999;
vector<int>edge[30500];
vector<int>cost[30500];
bool taken[30500];
int N,M,L;

long go(int r,long v)
{
    int i,j,k,flag=0;
    long sum=-inf;
    for(i=0;i<edge[r].size();i++)
    {
        k=edge[r][i];
        if(taken[k]==0)
        {
            flag=1;
            taken[k]=1;
            sum=max(go(k,v+cost[r][i]),sum);
        }
    }
    if(flag==0)
    {
        if(M==-1)
        {
            M=v;
            N=r;
            return v;
        }
        else if(M<v)
        {
            M=v;
            N=r;
            return v;
        }
        else
            return v;

    }
    return sum;
}

main()
{
    int t=1,tc;
    scanf("%d",&tc);
    while(tc--)
    {
        int n,i,j,k,l;
        scanf("%d",&n);
        for(i=0;i<n-1;i++)
        {
            scanf("%d%d%d",&j,&k,&l);
            edge[j].push_back(k);
            edge[k].push_back(j);
            cost[j].push_back(l);
            cost[k].push_back(l);
        }
        memset(taken,0,sizeof(taken));
        taken[0]=1;
        M=-1;
        long sum=go(0,0);
        memset(taken,0,sizeof(taken));
        taken[N]=1;
        M=-1;
        sum=go(N,0);
        printf("Case %d: %d\n",t++,sum);
        for(i=0;i<n;i++)
            edge[i].clear();
        for(i=0;i<n;i++)
            cost[i].clear();
    }
    return 0;
}

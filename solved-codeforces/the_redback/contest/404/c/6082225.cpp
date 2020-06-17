/**
 *    @author     : Maruf Tuhin
 *    @School     : CUET CSE 11
 *    @Topcoder   : the_redback
 *    @CodeForces : the_redback
 *    @UVA        : the_redback
 *    @link       : maruf.2hin@gmail.com
 */
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<stack>
using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define pp pop_back
#define inf 10000000
#define NN 100010

struct D
{
    int p,v;
};

D a[NN];

bool comp(D c,D b)
{
    return c.v<b.v;
}

int viw[NN];
vector<int>e[NN];
vector<int>vv[NN];

main()
{
    ios_base::sync_with_stdio(false);
    int t,tc;
    int i,j,k,l;
    int res,u,w,p,n,x,y,z,m,q,r,v,zero;
    D data;
    //cin>>tc;
    while(cin>>n>>k)
    {
        mem(viw,0);
        int MAX=-inf;
        for(i=0; i<n; i++)
        {
            cin>>r;
            data.p=i;
            data.v=r;
            a[i]=data;
            viw[r]++;
            vv[r].pb(i);
            if(r==0)
                zero=i;
            MAX=max(r,MAX);
        }
        int ret=0,flag=1;
        if(viw[0]!=1)
        {
            printf("-1\n");
            continue;
        }

        sort(a,a+n,comp);
        ret=0;
        for(i=0; i<n; i++)
        {
            viw[i]=k;
        }
        for(i=1; i<n; i++)
        {
            v=a[i].v;
            p=a[i].p;
            flag=1;
             viw[p]--;
            for(j=0; j<vv[v-1].size() && flag; j++)
            {
                l=vv[v-1][j];
                if(viw[l]>0)
                {
                    viw[l]--;
                    flag=0;
                }
            }
            if(flag==1)
            {
                printf("-1");
                return 0;
            }
            e[p].pb(l);
            ret++;
        }
        printf("%d\n",ret);
        for(i=0; i<n; i++)
        {
            for(j=0; j<e[i].size(); j++)
                printf("%d %d\n",i+1,e[i][j]+1);
        }
    }
    return 0;
}


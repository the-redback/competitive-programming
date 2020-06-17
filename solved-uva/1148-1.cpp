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

#define inf HUGE_VAL
#define mem(a,b) memset(a,b,sizeof(a))
#define NN 100000
vector<int>edge[NN+7];
int dist[NN+7];
queue<int>q;
int dr[]={0,-1,0,1};
int dc[]={-1,0,1,0};
int R,C;
int bfs(int src,int dst)
{
    q=queue<int>();
    mem(dist,-1);
    q.push(src);
    dist[src]=0;
    while(!q.empty())
    {
        int k=q.front();
        q.pop();
        for(int i=0; i<edge[k].size(); i++)
        {
            if(dist[edge[k][i]]==-1)
            {
                q.push(edge[k][i]);
                dist[edge[k][i]]=dist[k]+1;
                if(edge[k][i]==dst)
                    return dist[k];
            }
        }
    }
    return 0;
}

main()
{
    //freopen("C:\\Users\\Maruf Tuhin\\Desktop\\in.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    int i,j,k,l,n,r,c;
    int tc,t=1;
    cin>>tc;
    while(tc--)
    {
        cin>>n;
        for(i=0; i<n; i++)
        {
            cin>>r>>k;
            while(k--)
                cin>>c,edge[r].push_back(c),edge[c].push_back(r);
        }
        cin>>k>>l;
        int sum=bfs(k,l);
        if(t!=1)
            cout<<"\n";
        cout<<k<<" "<<l<<" "<<sum<<"\n";
        t++;
        for(i=0;i<=n;i++)
            edge[i].clear();
    }
    return 0;
}






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

#define mp make_pair
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 1e9
#define eps 1e-9
#define NN 1050

bool wish[NN];
bool color[NN];
vector<int>arr;          //topological sorted node
vector<int>e[NN],ne[NN];        //Graph Before SCC
vector<int>te[NN];       //Transpose Graph Before SCC
vector<pair<int,int> >v; //Edges Before SCC
map<pair<int,int>,int >mmp;
int id[NN];              //Id of Nodes After SCC
int in[NN],out[NN];


int dfs_1st(int u)
{
    color[u]=true;
    for(int i=0; i<e[u].size(); i++)
    {
        if(!color[e[u][i]])
            dfs_1st(e[u][i]);
    }
    arr.pb(u);
}

int dfs_2nd(int u,int k)
{
    color[u]=true;
    id[u]=k;

    for(int i=0; i<te[u].size(); i++)
    {
        if(!color[te[u][i]])
            dfs_2nd(te[u][i],k);
    }
}

string scc(int n)
{
    arr.clear();
    mem(color,0);
    int i,j,k,l;

    for(i=0; i<=n; i++)
        if(color[i]==0 && wish[i])
            dfs_1st(i);

    reverse(all(arr));

    mem(id,-1);
    mem(color,0);
    k=0;

    for(i=0; i<arr.size(); i++)
    {
        if(!color[arr[i]])
            dfs_2nd(arr[i],k+1),k++;
    }

    int node=k;

    mem(in,0);
    mem(out,0);

    int flag=0;

    for(i=0; i<v.size(); i++)
    {
        k=v[i].first;
        l=v[i].second;

        if(id[k]!=id[l])
            ne[id[k]].pb(id[l]),out[id[k]]++,in[id[l]]++,flag=1;
    }
    int cnt=0;
    if(out[id[0]]==0 && flag)
        return "NO";
    for(i=1; i<=node; i++)
    {
        if(in[i]!=out[i])
        {
            cnt++;
        }
        if(cnt>2 || abs(in[i]-out[i])>=2)
            return "NO";
    }
    flag=1;
    k=id[0];
    mem(color,0);
    color[k]=true;
    while(flag)
    {
        flag=0;
        for(i=0;i<ne[k].size();i++)
        {
            if(!color[ne[k][i]])
            {
                color[ne[k][i]]=true;
                k=ne[k][i];
                flag=1;
                break;
            }
        }
    }
    for(i=0;i<=n;i++)
    {
        if(wish[i]&& !color[id[i]])
            return "NO";
    }

    return "YES";
}


main()
{
    ios_base::sync_with_stdio(false);
    int t=1,tc;
    int i,j,k,l,m,n,man;

    cin>>tc;    //Test Case
    while(tc--)
    {
        cin>>n; //n=node, m=edge
        int w;
        int mx=0;
        mem(wish,0);
        mmp.clear();
        for(i=0; i<n; i++)
        {
            cin>>w;
            while(w--)
            {
                cin>>k>>l;
                if(mmp.find(mp(k,l))==mmp.end())
                {
                    e[k].pb(l);
                    te[l].pb(k);
                    v.pb(make_pair(k,l));
                    wish[k]=wish[l]=true;
                    mx=max(mx,k);
                    mx=max(mx,l);
                    mmp[mp(k,l)]=1;
                }

            }
        }
        string sum=scc(mx);
        printf("Case %d: %s\n",t++,sum.c_str());
        for(i=0; i<=mx; i++)
        {
            e[i].clear();
            te[i].clear();
            ne[i].clear();
        }
        v.clear();
    }
    return 0;
}

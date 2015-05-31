/**
 *    @author     : Maruf Tuhin
 *    @School     : CUET CSE 11
 *    @Topcoder   : the_redback
 *    @CodeForces : the_redback
 *    @UVA        : the_redback
 *    @link       : http://www.fb.com/maruf.2hin
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef unsigned long long llu;

#define ft        first
#define sd        second
#define mp        make_pair
#define pb(x)     push_back(x)
#define all(x)    x.begin(),x.end()
#define allr(x)   x.rbegin(),x.rend()
#define mem(a,b)  memset(a,b,sizeof(a))
#define meminf(a) memset(a,126,sizeof(a))
#define inf       1e11
#define eps       1e-9
#define mod       1000000007
#define NN        100010

//cout << setfill('0') << setw(3) << a << endl;
//cout << fixed << setprecision(20) << a << endl;


vector<int>e[NN];
map<string,int>mpp;
int color[NN];
int fl;

void dfs(int u)
{
    color[u]=1;
    for(int i=0;i<e[u].size();i++)
    {
        int v=e[u][i];
        if(!color[v])
            dfs(v);
        else if(color[v]==1)
        {
            fl=-1;
            return;
        }
    }
    color[u]=2;
    return;
}

string s,ss;

main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t=0,tc;
    int n,m,i,j,l;
    cin>>tc;
    while(tc--)
    {
        cin>>m;
        int r=0;
        n=0;
        for(i=0;i<m;i++)
        {
            cin>>s>>ss;
            if(mpp.find(s)==mpp.end())    mpp[s]=r++;
            if(mpp.find(ss)==mpp.end())   mpp[ss]=r++;

            e[mpp[ss]].pb(mpp[s]);
        }
        mem(color,0);
        fl=0;
        for(i=0;i<r;i++)
        {
            if(!color[i])
                dfs(i);

            if(fl==-1)
                break;
        }
        if(fl!=-1)
            printf("Case %d: Yes\n",++t);
        else
            printf("Case %d: No\n",++t);
        for(i=0;i<r;i++)
            e[i].clear();
        mpp.clear();
    }
    return 0;
}

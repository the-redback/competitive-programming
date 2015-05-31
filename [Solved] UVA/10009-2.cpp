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
#define NN 50
string s;
string ss;
vector<int>edge[NN+7];
map<string,int>mp;
int dist[NN+7];
queue<int>q;
vector<string>city;
char a[1050];
char c[1050];

void bfs(int src,int dest)
{
    q=queue<int>();
    q.push(src);
    mem(dist,-1);
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
                dist[edge[k][i]]=k;
                if(edge[k][i]==dest)
                    return;
            }
        }
    }
    return;
}

void go(int n)
{
    if(n<1)
        return;
    go(dist[n]);
    printf("%c",city[n][0]);
    return;
}

main()
{
    //freopen("C:\\Users\\Maruf Tuhin\\Desktop\\in.txt","r",stdin);
    int i,j,k,l,n,r;
    int tc,t=1;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d%d",&n,&r);
        j=1;
        city.push_back("0");
        for(i=0; i<n; i++)
        {
            scanf("%s%s",&a,&c);
            s="";
            s.push_back(a[0]);
            ss="";
            ss.push_back(c[0]);
            if(mp.find(s)==mp.end())
            {
                mp[s]=j++;
                city.push_back(s);
            }
            if(mp.find(ss)==mp.end())
            {
                mp[ss]=j++;
                city.push_back(ss);
            }
            edge[mp[s]].push_back(mp[ss]);
            edge[mp[ss]].push_back(mp[s]);
        }
        if(t!=1)
            puts("");
        while(r--)
        {
            scanf("%s%s",&a,&c);
            s="";
            s.push_back(a[0]);
            ss="";
            ss.push_back(c[0]);
            bfs(mp[s],mp[ss]);
            go(dist[mp[ss]]);
            printf("%c\n",city[mp[ss]][0]);
        }
        for(i=0; i<NN; i++)
            edge[i].clear();
        mp.clear();
        city.clear();
        t++;
    }
    return 0;
}






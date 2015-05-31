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
#define NN 30

vector<int>e[NN+7],v;
int view[NN+7];
int pr[NN+7];
vector<string>vs;
char a[NN+7];


void dfs(int u)
{
    int i,k,l;
    view[u]=1;
    for(i=0; i<e[u].size(); i++)
    {
        if(view[e[u][i]]==0)
            dfs(e[u][i]);
    }
    v.pb(u);
}

int main()
{
    int i,j,k,l;
    int tc,t;
    int n,m;
    mem(pr,0);
    while(~scanf("%s",&a))
    {
        if(a[0]=='#')
            break;
        for(i=0;a[i]!=0;i++)
            pr[a[i]-'A']=1;
        vs.pb(a);
    }
    mem(view,0);

    for(i=0; i<vs.size()-1; i++)
    {
        j=0;
        while(j<vs[i].size() && j<vs[i+1].size())
        {
            if(vs[i][j]!=vs[i+1][j])
            {
                e[vs[i][j]-'A'].pb(vs[i+1][j]-'A');
                break;
            }
            j++;
        }
    }
    for(i=0; i<=26; i++)
    {
        if(pr[i]==1 && view[i]==0)
            dfs(i);
    }
    reverse(v.begin(),v.end());
    for(i=0; i<v.size(); i++)
        printf("%c",v[i]+'A');
    puts("");
    v.clear();
    vs.clear();
    for(i=0; i<=26; i++)
        e[i].clear();
    return 0;
}

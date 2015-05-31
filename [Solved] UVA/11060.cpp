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
#define NN 5000

map<string,int>mp;
vector<int>e[NN+7];
vector<int>v;
vector<string>ans;
int pr[NN+7];
string s,ss;
char a[100],b[100];

void topological(int n)
{
    int i,j,k,l,in;
    while(v.size()<n)
    {
        int mn=inf;
        for(i=0;i<n;i++)
            if(mn>pr[i])
                mn=pr[i],in=i;
        pr[in]=inf;
        v.pb(in);
        for(i=0;i<e[in].size();i++)
            pr[e[in][i]]--;
    }
}

main()
{
    int tc,t=1;
    int i,j,k,l,m,n,count;
    //scanf("%d",&tc);
    while(~scanf("%d",&n))
    {
        for(i=0;i<n;i++)
        {
            scanf("%s",&a);
            s.assign(a);
            mp[s]=i;
            ans.pb(s);
            pr[i]=0;
        }
        scanf("%d",&m);
        while(m--)
        {
            scanf("%s%s",&a,&b);
            s.assign(a);
            ss.assign(b);
            pr[mp[ss]]++;
            e[mp[s]].pb(mp[ss]);
        }
        topological(n);
        printf("Case #%d: Dilbert should drink beverages in this order:",t++);
        for(i=0;i<n;i++)
        {
            printf(" %s",ans[v[i]].c_str());
            e[i].clear();
        }
        printf(".\n\n");
        mp.clear();
        v.clear();
        ans.clear();
    }
    return 0;
}






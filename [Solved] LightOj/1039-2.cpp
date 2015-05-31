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

string s,ss,src,dist,s1,s2,s3;
char a[100];
int vis[18000];
map<string, int>premap;
queue<string>q;

void go(void)
{
    char i,j,k;
    int r=1;
    for(i='a'; i<='z'; i++)
        for(j='a'; j<='z'; j++)
            for(k='a'; k<='z'; k++)
            {
                s="";
                s=i;
                s+=j;
                s+=k;
                premap[s]=r++;
            }
}

main()
{
    go();
//    ios_base::sync_with_stdio(0); cin.tie(0);
    int t=1,tc;
    scanf("%d",&tc);
    int i,j,k,l,m,n;
    while(tc--)
    {
        scanf("%s",&a);
        src.assign(a);
        scanf("%s",&a);
        dist.assign(a);
        scanf("%d",&n);
        q=queue<string>();
        mem(vis,-1);
        while(n--)
        {
            scanf("%s",&a);
            s1.assign(a);
            scanf("%s",&a);
            s2.assign(a);
            scanf("%s",&a);
            s3.assign(a);
            for(i=0; i<s1.size(); i++)
                for(j=0; j<s2.size(); j++)
                    for(k=0; k<s3.size(); k++)
                    {
                        ss="";
                        ss+=s1.substr(i,1);
                        ss+=s2.substr(j,1);
                        ss+=s3.substr(k,1);
                        vis[premap[ss]]=-2;
                    }
        }
        if(vis[premap[dist]]==-2||vis[premap[src]]==-2)
        {
            printf("Case %d: -1\n",t++);
            continue;
        }
        if(src==dist && vis[premap[src]]==-1)
        {
            printf("Case %d: 0\n",t++);
            continue;
        }
        else if(vis[premap[src]]==-1)
            q.push(src),vis[premap[src]]=0;
        while(q.size())
        {
            s=q.front(),q.pop();
            ss=s;
            ss[0]-=1;
            if(ss[0]<'a')
                ss[0]='z';
            //cout<<ss<<"\n";
            if(vis[premap[ss]]==-1)
            {
                q.push(ss);
                vis[premap[ss]]=vis[premap[s]]+1;
                if(ss==dist)
                    break;
            }
            ss=s;
            ss[0]+=1;
            if(ss[0]>'z')
                ss[0]='a';
            if(vis[premap[ss]]==-1)
            {
                q.push(ss);
                vis[premap[ss]]=vis[premap[s]]+1;
                if(ss==dist)
                    break;
            }
            ss=s;
            ss[1]-=1;
            if(ss[1]<'a')
                ss[1]='z';
            if(vis[premap[ss]]==-1)
            {
                q.push(ss);
                vis[premap[ss]]=vis[premap[s]]+1;
                if(ss==dist)
                    break;
            }
            ss=s;
            ss[1]+=1;
            if(ss[1]>'z')
                ss[1]='a';
            if(vis[premap[ss]]==-1)
            {
                q.push(ss);
                vis[premap[ss]]=vis[premap[s]]+1;
                if(ss==dist)
                    break;
            }
            ss=s;
            ss[2]-=1;
            if(ss[2]<'a')
                ss[2]='z';
            if(vis[premap[ss]]==-1)
            {
                q.push(ss);
                vis[premap[ss]]=vis[premap[s]]+1;
                if(ss==dist)
                    break;
            }
            ss=s;
            ss[2]+=1;
            if(ss[2]>'z')
                ss[2]='a';
            if(vis[premap[ss]]==-1)
            {
                q.push(ss);
                vis[premap[ss]]=vis[premap[s]]+1;
                if(ss==dist)
                    break;
            }
        }
        printf("Case %d: %d\n",t++,vis[premap[dist]]);

    }
    return 0;
}

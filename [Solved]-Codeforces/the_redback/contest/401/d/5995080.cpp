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
#define LL __int64
#define inf 10000000
#define NN 2000100
vector <char>v;
char a[22];
int vis[22];
LL dp[1<<18][101];
int n,md;
LL call(int mask, int m)
{
    if(mask==(1<<n)-1)
    {
        if(m==0)
            return 1;
        else
            return 0;
    }
    LL &tc=dp[mask][m];
    if(tc!=-1)
        return tc;
    LL res=0;
    for(int i=0;i<n;i++)
    {
        if((mask & 1<<i)== 0)
        {
            if(mask==0 && a[i]=='0')
                continue;
            if(i==0||a[i]!=a[i-1]||(mask&1<<(i-1))==0)
                res+=call(mask|1<<i,(m*10+(a[i]-'0'))%md);
        }
    }
    return tc=res;
}

main()
{
    int t,tc;
    int i,j,k,l;
    int u,w,p,x,y,z,m,q;
    //cin>>tc;
    while(~scanf("%s%d",&a,&md))
    {
        n=strlen(a);
        mem(dp,-1);
        sort(a,a+n);
        LL res=call(0,0);
        printf("%I64d\n",res);
    }
    return 0;
}

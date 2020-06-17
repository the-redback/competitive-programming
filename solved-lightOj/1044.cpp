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

#define ft first
#define sd second
#define ll __int64
#define mp make_pair
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 1e9
#define eps 1e-9
#define NN 1010

int dp[NN][NN];
int dpp[NN][NN];

char a[NN];

int palin(int i,int j)
{
    if(i>=j)
        return 1;
    int &tc=dpp[i][j];
    if(tc!=-1)
        return tc;
    if(a[i]!=a[j])
        return tc=0;
    return tc=palin(i+1,j-1);
}

int part(int i,int j)
{
    if(i>=j)
        return 1;
    int &tc=dp[i][j];
    if(tc!=-1)
        return tc;
    if(palin(i,j))
        return tc=1;
    int res=inf;
    for(int k=i;k<j && res>2;k++)
    {
        if(palin(i,k))
            res=min(res,part(k+1,j)+1);
    }
    return tc=res;
}

main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    int t=1,tc;
    cin>>tc;
    int i,j,k,l,n,m;
    while(tc--)
    {
        scanf("%s",a);
        l=strlen(a);
        mem(dpp,-1);
        mem(dp,-1);
        int res=part(0,l-1);
        printf("Case %d: %d\n",t++,res);
    }
    return 0;
}

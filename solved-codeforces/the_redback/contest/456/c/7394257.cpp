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
#define ll __int64
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 1e9
#define eps 1e-9
#define NN 100050


int a[NN];
ll b[NN];
ll dp[NN][3];

ll rec(int k,int flag)
{
    if(k<0)
        return 0;
    ll &tc=dp[k][flag];
    if(tc!=-1)
        return tc;
    ll ret=0;
    ret=rec(k-1,0);
    if(flag==0)
    {
        ret=max(ret,rec(k-1,1)+b[k]);
    }
    tc=ret;
    return tc;
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t,tc;
    //cin>>tc;
    __int64 sum,ret;
    int i,j,mx;
    __int64 m,k,l;
    int n;
    while(cin>>n)
    {
        mem(a,0);
        mem(dp,-1);
        mx=0;

        for(i=0; i<n; i++)
        {
            cin>>t;
            a[t]++;
            mx=max(mx,t);
        }
        for(i=0; i<=mx; i++)
        {
            k=i;
            l=a[i];
            b[i]=k*l;
        }
        ret=rec(mx,0);
        printf("%I64d\n",ret);
    }
    return 0;
}

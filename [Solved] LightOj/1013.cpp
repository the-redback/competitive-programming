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

//==================[ START ]=====================

typedef unsigned long long LLU;
typedef long long LL;

#define ft first
#define sd second
#define mp make_pair
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()
#define allr(x) x.rbegin(),x.rend()
#define mem(a,b) memset(a,b,sizeof(a))
#define meminf(a) memset(a,126,sizeof(a))
#define LL long long
#define LLU unsigned long long

#define inf 1e9
#define eps 1e-9
#define NN 1010
//==================[ END ]=====================

LL dp[35][35];
LL dlcs[35][35];
string s1,s2;

LL lcs(int i,int j)
{
    if(i<=0 ||j<=0)
        return 0;
    LL &tc=dlcs[i][j];
    if(tc!=-1)
        return tc;
    if(s1[i]==s2[j])
        tc=lcs(i-1,j-1)+1;
    else
    {
        LL res=lcs(i-1,j);
        tc=max(res,lcs(i,j-1));
    }
    return tc;
}

LL rec(int i,int j)
{
    if(i<=0 ||j<=0)
        return 1;
    LL &tc=dp[i][j];
    if(tc!=-1)
        return tc;
    if(s1[i]==s2[j])
        tc=rec(i-1,j-1);
    else if(lcs(i-1,j)>lcs(i,j-1))
        tc=rec(i-1,j);
    else if(lcs(i-1,j)<lcs(i,j-1))
        tc=rec(i,j-1);
    else
        tc=rec(i-1,j)+rec(i,j-1);
    return tc;
}

main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t=1,tc;
    cin>>tc;
    LL i,j,k,l,m,n;
    LL r,q;
    while(tc--)
    {
        cin>>s1;
        cin>>s2;
        s1=" "+s1;
        s2=" "+s2;
        mem(dp,-1);
        mem(dlcs,-1);

        LL res=s1.size()+s2.size()-2;
        res-=lcs(s1.size()-1,s2.size()-1);
        LL ret=rec(s1.size()-1,s2.size()-1);
        printf("Case %d: %lld %lld\n",t++,res,ret);
    }
    return 0;
}

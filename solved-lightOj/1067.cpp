/**
 *    @author     : Maruf Tuhin
 *    @School     : CUET CSE 11
 *    @Topcoder   : the_redback
 *    @Codeforces : the_redback
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
#define mod 1000003
#define NN 1000001
int fact[NN+7];
int go(int n,int q)
{
    if(q==1)
        return n%mod;
    if(q%2)
        return ((long long)(n%mod)*go(n,q-1))%mod;
    else
    {
        int k=go(n,q/2);
        return ((long long)k*k)%mod;
    }
}

main()
{
    int n,k,l,r,i;
    int tc,t=1;
    fact[0]=1;
    for(i=1;i<NN;i++)
        fact[i]=((long long)i*fact[i-1])%1000003;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d%d",&n,&k);
        r=((long long)fact[k]*fact[n-k])%mod;
        int inmod=go(r,mod-2)%mod;
        int ans=((long long)fact[n]*inmod)%mod;
        printf("Case %d: %d\n",t++,ans);
    }
    return 0;
}

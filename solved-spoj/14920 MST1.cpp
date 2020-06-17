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
#define NN 20000000

int dp[NN+7];

void go(void)
{
    dp[1]=0;
    dp[2]=1;
    dp[3]=1;
    for(int i=4;i<=NN;i++)
    {
        dp[i]=dp[i-1]+1;
        if(i%3==0)
            dp[i]=min(dp[i],1+dp[i/3]);
        if(i%2==0)
            dp[i]=min(dp[i],1+dp[i/2]);
    }
    return;
}

main()
{
    ios_base::sync_with_stdio(false);
    int t=1,tc;
    go();
    cin>>tc;
    int n;
    while(tc--)
    {
        cin>>n;
        printf("Case %d: %d\n",t++,dp[n]);
    }
    return 0;
}

/*
Input:
 3
 1
 4
 7

Output:
Case 1: 0
Case 2: 2
Case 3: 3
*/

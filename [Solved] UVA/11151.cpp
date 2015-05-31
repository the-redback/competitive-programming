#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
#include<stack>
using namespace std;
char a[1010];
char b[1010];
int dp[1010][1010];
int LCS(int i,int j)
{
    if(i<0 || j<0)
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    if(a[i]==b[j])
        return dp[i][j]=LCS(i-1,j-1)+1;
    return dp[i][j]=max(LCS(i,j-1),LCS(i-1,j));
}

main()
{
    int l,tc;
    cin>>tc;
    getchar();
    while(tc--)
    {
        gets(a);
        l=strlen(a);
        if(l==0)
        {
            puts("0");
            continue;
        }
        strcpy(b,a);
        reverse(b,b+l);
        memset(dp,-1,sizeof(dp));
        int k=LCS(l-1,l-1);
        printf("%d\n",k);
    }
    return 0;
}

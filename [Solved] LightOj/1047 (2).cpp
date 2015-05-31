#include <bits/stdc++.h>
using namespace std;
int dp[21][3];
int a[21][3];
int n;
int test(int i,int j)
{
    int b,c;
    if(dp[i][j]!=-1)
        return dp[i][j];

    else if(i>=n)
        return 0;

    else if(j==0)
    {
        b=test(i+1,1)+a[i][j];
        c=test(i+1,2)+a[i][j];
    }
    else if(j==1)
    {
        b=test(i+1,0)+a[i][j];
        c=test(i+1,2)+a[i][j];
    }
    else if(j==2)
    {
        b=test(i+1,0)+a[i][j];
        c=test(i+1,1)+a[i][j];
    }

    if(b>c)
        dp[i][j]=c;

    else
        dp[i][j]=b;

    return dp[i][j];
}

main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int i,j,k,l,t;
    int b[3];
    cin>>t;
    for(i=1;i<=t;i++)
    {
        for(j=0;j<21;j++)
        {
            dp[j][0]=-1;
            dp[j][1]=-1;
            dp[j][2]=-1;
        }
        cin>>n;
        for(j=0;j<n;j++)
        {
            cin>>a[j][0]>>a[j][1]>>a[j][2];
        }
        int mx=10000000;
        mx=test(0,0);
        mx=min(mx,test(0,1));
        mx=min(mx,test(0,2));

        printf("Case %d: %d\n",i,mx);
    }
    return 0;
}

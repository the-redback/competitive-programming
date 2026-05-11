/**
 *                                   ____
 *       ____ ___  ____ ________  __/ __/
 *      / __ `__ \/ __ `/ ___/ / / / /_
 *     / / / / / / /_/ / /  / /_/ / __/
 *    /_/ /_/ /_/\__,_/_/   \__,_/_/
 *
 *    @link : https://the-redback.com
 */
//#include <bits/stdc++.h>
#include <bits/stdc++.h>
using namespace std;
#define inf HUGE_VAL

int dp[1050000][6];
int arr[30];
int n,dv,FLAG;
int go(int mask,int flag,int value)
{
    if(mask==(1<<n)-1)
    {
        if(value==dv && flag==4)
        {
            FLAG=1;
            return 1;
        }
        else
            return 0;
    }
    if(FLAG==1)
        return 1;
    if(value==dv)
    {
        return go(mask,flag+1,0);
    }
    int &tc=dp[mask][flag];
    if(tc!=-1)
        return tc;
    int ret=0;
    for(int i=0;i<n;i++)
    {
        if(FLAG==1)
            return tc=1;
        if(!(mask&1<<i) && value+arr[i]<=dv)
        {
            ret=max(ret,go(mask|1<<i,flag,value+arr[i]));
        }
    }
    tc=ret;
    return ret;
}

main()
{
    int tc,t=1;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d",&n);
        int sum=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
            sum+=arr[i];
        }
        if(sum%4!=0)
            puts("no");
        else
        {
            dv=sum/4;
            memset(dp,-1,sizeof(dp));
            FLAG=0;
            int ret=go(0,1,0);
            if(FLAG==0)
                puts("no");
            else
                puts("yes");
        }
    }
}

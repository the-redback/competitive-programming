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
#define inf 9999999
int dp[1050][1050];
char arr[20];
int n,N;
int go(int mask,int mod)
{
    if(mask==(1<<N)-1)
    {
        if(mod==0)
            return 1;
        else
            return 0;
    }
    int &t=dp[mask][mod];
    if(t!=-1)
        return t;
    int sum=0;
    int i,k;
    for(i=0; i<N; i++)
    {
        if(!(mask&1<<i))
            if(i==0||arr[i]!=arr[i-1]||(mask&1<<(i-1)))
            {
                sum+=go(mask|1<<i,(mod*10+arr[i]-'0')%n);
            }
    }
    t=sum;
    return sum;
}

main()
{
    int t=1,tc;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%s %d",&arr,&n);
        N=strlen(arr);
        sort(arr,arr+N);
        memset(dp,-1,sizeof(dp));
        int sum=go(0,0);
        printf("Case %d: %d\n",t++,sum);
    }
    return 0;
}

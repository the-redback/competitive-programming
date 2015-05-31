#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
int a[25],N,n;
int dp[25][200];
bool dc[25][200];

int call(int k,int rem)
{
    if(k==n)
    {
        if(rem==N)
            return 1;
        else
            return 0;
    }
    if(rem==N)
        return 1;
    if(dc[k][rem])
        return dp[k][rem];
    int x=0,y=0;
    if(a[k]+rem<=N)
        x=call(k+1,a[k]+rem);
    y=call(k+1,rem);
    dc[k][rem]=1;
    return dp[k][rem]=max(x,y);
}

main()
{
    char ch;
    int i,j,k,S,sum,t;
    scanf("%d",&t);
    getchar();
    while(t--)
    {
        n=0,sum=0,k=0;
        while(ch=getchar())
        {
            if(ch>='0' &&ch<='9')
            {
                k=k*10+ch-'0';
            }
            else if(ch==' '||ch=='\n')
            {
                a[n]=k;
                sum+=k;
                k=0;
                n++;
            }
            if(ch=='\n')
                break;
        }
        if(sum%2==1)
        {
            puts("NO");
            continue;
        }
        memset(dc,0,sizeof(dc));
        N=sum/2;
        if(call(0,0))
        {
            puts("YES");
        }
        else
            puts("NO");
    }
    return 0;
}

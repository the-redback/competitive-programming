///=======================================//
///    Author     : Maruf Tuhin           //
///    School     : CUET CSE 11           //
///    TopCoder   : the_redback           //
///    Codeforces : maruf.2hin            //
///    UVA        : Redback               //
///    http://www.fb.com/maruf.2hin       //
///=======================================//
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define MAX 1010
#define inf 999999

int dp[MAX][MAX][3];
bool dc[MAX][MAX][3];
int I,J,K,L,N;
int a[MAX];
int go(int pos,int prev,int flag)
{
    if(pos>N)
    {
            return 0;
    }
    int &t=dp[pos][prev][flag];
    bool &bl=dc[pos][prev][flag];
    if(bl)
        return t;
    int ret=0;
    if(pos==N)
    {
        if(pos!=prev+1 && flag!=1)
            ret=a[pos]+go(pos+1,pos,flag);
        else
            ret=go(pos+1,prev,flag);
    }
    else if(pos==1)
        ret=a[pos]+go(pos+1,pos,1);
    else if(pos!=prev+1 || prev==0)
        ret=a[pos]+go(pos+1,pos,flag);
    ret=max(ret,go(pos+1,prev,flag));
    t=ret;
    bl=1;
    return ret;
}

main()
{
    int t=1,tc;
    scanf("%d",&tc);
    while(tc--)
    {
        int n,k,l,i;
        scanf("%d",&N);
        for(i=1;i<=N;i++)
        {
            scanf("%d",&a[i]);
        }
        memset(dc,0,sizeof(dc));
        int sum=go(1,0,0);
        printf("Case %d: %d\n",t++,sum);
    }
    return 0;
}

#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int pr[10010];
int sum[10010];
void sieve(void)
{
    int i,j;
    memset(pr,0,sizeof(pr));
    for(i=1;i<=10000;i++)
    {
        for(j=i*i;j<=10000;j+=i)
            pr[j]++;
    }
    sum[0]=0;
    for(i=1;i<=10000;i++)
        sum[i]=sum[i-1]+pr[i];
}
int main()
{
    int n;
    sieve();
    while(scanf("%d",&n)==1)
    {
        printf("%d\n",sum[n]);
    }
    return 0;
}

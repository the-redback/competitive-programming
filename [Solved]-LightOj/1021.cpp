
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
/*
=======[ Theme ]=======
LightOj: Painful Bases.

you are given a base, an integer K and
a valid number in the base which contains distinct digits.
output number of permutations of the given number
which are divisible by K. K is given in decimal.

*/
long long dp[66000][20];
char a[20];
int n,k,l;

int modul(char ch,int carry)
{
    int x;
    if(ch>='0' &&ch<='9')
        x=ch-'0';
    else
        x=ch-'A'+10;
    x+=carry*n;
    x=x%k;
    return x;
}

long long call(int pos,int mod)
{
    if(pos==(1<<l)-1)
    {
        if(mod==0)
            return 1;
        else
            return 0;
    }
    long long &t=dp[pos][mod];
    if(t!=-1)
        return t;
    long long sum=0;
    for(int i=0;i<l;i++)
    {
        if(!(pos&1<<i))
        {
            int x=modul(a[i],mod);
            sum+=call(pos|1<<i,x);
        }
    }
    t=sum;
    return sum;
}


main()
{
    int tc,t=1;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d%d",&n,&k);
        getchar();
        gets(a);
        memset(dp,-1,sizeof(dp));
        l=strlen(a);
        long long sum=call(0,0);
        printf("Case %d: %lld\n",t++,sum);
    }
    return 0;
}

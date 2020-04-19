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

bool p[106];
vector<int>pr;
int mx;
int fact[10001];
void sieve(int n)
{
    int i,j,k,l;
    p[1]=1;
    pr.push_back(2);
    for(i=4;i<=n;i+=2)
        p[i]=1;
    for(i=3;i<=n;i+=2)
    {
        if(!p[i])
        {
            pr.push_back(i);
            for(j=i*i;j<=n;j+=2*i)
                p[j]=1;
        }
    }
}

void factor(int n)
{
    int i,j,count,k=n;
    for(j=0;j<pr.size() && pr[j]*pr[j]<=n;j++)
    {
        i=pr[j];
        count=0;
        if(n%i==0)
        {
            mx=max(i,mx);
        }
        while(n%i==0)
        {
            n/=i;
            count++;
        }
        fact[i]=count;
        if(n==1)
            break;
    }
    if(n>1)
    {
        mx=max(n,mx);
        fact[n]=1;
    }

}


int go(int n,int r)
{
    int sum=0,i=1;
    while(1)
    {
        int k=pow(r,i);
        if(k>n)
            break;
        sum+=n/k;
        i++;
    }
    return sum;
}

main()
{
    sieve(101);
    int n,k,i,m,c;
    int tc,t=1;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d%d",&m,&n);
        mem(fact,0);
        mx=-inf;
        int ans=inf;
        factor(m);
        for(i=2;i<=mx;i++)
        {
            if(fact[i])
            {
                k=go(n,i);
                ans=min(ans,k/fact[i]);
            }
        }
        if(!ans)
            printf("Case %d:\nImpossible to divide\n",t++);
        else
            printf("Case %d:\n%d\n",t++,ans);
    }
    return 0;
}

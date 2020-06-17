#include <string.h>
#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;
bool pr[10000];

void sieve(int n)
{
    memset(pr,0,sizeof(pr));
    int i,j,k,l;
    pr[1]=1;
    for(i=4;i<=n;i+=2)
        pr[i]=1;
    for(i=3;i*i<=n;i+=2)
    {
        if(pr[i]==0)
        {
            for(j=i*i;j<=n;j+=2*i)
                pr[j]=1;
        }
    }
}
long long check(int n)
{
    long long i=1,m,sum=1;
    while(i*i<=n)
    {
         m=0;
         while(pr[i]!=0 && i*i<=n)
            i++;
        while(n%i==0 && n!=0)
        {
            n=n/i;
            m++;
        }
        sum*=((pow(i,m+1))-1)/(i-1);
        if(n==0)
            break;
        i++;
    }
    if(n!=1)
        sum*=((n*n)-1)/(n-1);
    return sum;
}

main()
{
    int tc,t;
    cin>>tc;
    sieve(1000);
    for(t=1; t<=tc; t++)
    {
        int n;
        scanf("%d",&n);
        long long m=check(n);
        m-=n;
        printf("%lld\n",m);

    }
    return 0;
}

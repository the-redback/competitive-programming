#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool pr[50001];

void sieve(int n)
{
    memset(pr,0,sizeof(pr));
    long i,j,k,l;
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

main()
{
    vector<long long>v;
    sieve(50000);
    long long n,m;
    long long k;
    long long i;
    int j,t;
    while(scanf("%lld",&m))
    {
        if(m==0)
            return 0;
        if(m<0)
        {
            n=m*-1;
        }
        else
            n=m;
        k=n;
        for(i=2;i*i<=n;i++)
        {
            while(pr[i])
            {
                i++;
            }
            while(k%i==0)
            {
                k/=i;
                v.push_back(i);
            }
            if(k==1)
                break;
        }
        printf("%lld = ",m);
        t=0;
        if(m<0)
            {
                printf("-1");
                t=1;
            }
        for(i=0;i<v.size();i++)
        {
            if(t!=0)
                printf(" x ");
            printf("%lld",v[i]);
            t=1;
        }
        if(k!=1)
        {
            if(t!=0)
                printf(" x ");
            printf("%lld",k);
        }
        printf("\n");
        v.clear();
    }
    return 0;
}

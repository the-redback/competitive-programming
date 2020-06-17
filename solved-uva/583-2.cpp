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
vector<long long>v;
long long last_digit;
void sieve(int n)
{
    memset(pr,0,sizeof(pr));
    long i,j,l;
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
void prime_diviser(long long n)
{
    long long i;
    last_digit=n;
    for(i=2;i*i<=n;i++)
        {
            while(pr[i])
            {
                i++;
            }
            while(last_digit%i==0)
            {
                last_digit/=i;
                v.push_back(i);
            }
            if(last_digit==1)
                break;
        }
}

main()
{
    sieve(50000);
    int j,t;
    long long m,n,i;
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

        prime_diviser(n);
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
        if(last_digit!=1)
        {
            if(t!=0)
                printf(" x ");
            printf("%lld",last_digit);
        }
        printf("\n");
        v.clear();
    }
    return 0;
}

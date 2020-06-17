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
#define MAX 1000000
long long sum;
bool pr[MAX];
vector<long long>v;

void sieve(int n)
{
    long long i,j,k;
    for(i=4;i<n;i+=2)
        pr[i]=1;
    for(i=3;i<n;i+=2)
        if(!pr[i])
            for(j=i*i;j<n;j+=2*i)
                pr[j]=1;
    for(i=2;i<n;i++)
        if(!pr[i])
            v.push_back(i);
}


void phi(long long n)
{
    long long ret=0,j;
    long long i;
    sum=1;
    int sz=v.size();
    for(j=0;j<sz && v[j]*v[j]<=n;j++)
    {
        i=v[j];
        ret=0;
        while(!(n%i))
        {
            n/=i;
            ret++;
        }
        sum*=ret+1;
        if(n==1)
            break;
    }
    if(n>1)
        sum*=2;
    sum-=1;
}

main()
{
    sieve(MAX);
    int tc,t=1;
   // int i,j,k,l,x;
    long long k;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%lld",&k);
        phi(k);
        printf("Case %d: %lld\n",t++,sum);
    }
    return 0;
}

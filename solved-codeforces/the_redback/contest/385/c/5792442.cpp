/**
 *    @author     : Maruf Tuhin
 *    @School     : CUET CSE 11
 *    @Topcoder   : the_redback
 *    @CodeForces : the_redback
 *    @UVA        : the_redback
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

#define mem(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define pp pop_back
#define inf 1000000000
#define NN 10000000
__int64 a[NN+7];
bool p[NN+7]; //Hashing
vector<int>pr; //storing prime
int mx;
void sieve(int n)
{
    long long i,j,k,l;
    p[1]=1;
    pr.push_back(2);
    for(i=4; i<=n; i+=2)
        p[i]=1;
    for(i=3; i<=n; i+=2)
    {
        if(p[i]==0)
        {
            pr.push_back(i);
            for(j=i*i; j<=n; j+=2*i)
                p[j]=1;
        }
    }
}


void factor(int n)
{
    int count,k,i;
    for(i=0; i<pr.size() && pr[i]*pr[i]<=n; i++)
    {
        k=pr[i];
        if(n%k==0)
        {
            a[k]++;
            mx=max(mx,k);
            while(n%k==0)
            {
                n/=k;
            }
        }
        if(n==1)
            break;
    }
    if(n>1)
        a[n]++,mx=max(mx,n);
}

main()
{
    int tc,t=1;
    int i,j,k,l,m,n,count,r;
    sieve(NN);
    //scanf("%d",&tc);
    scanf("%d",&n);
    mx=0;
    while(n--)
    {
        scanf("%d",&k);
        factor(k);
    }
    for(i=1; i<=mx; i++)
        a[i]+=a[i-1];
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d%d",&k,&l);
        l=min(mx,l);
        k=min(mx+1,k);
        printf("%I64d\n",a[l]-a[k-1]);
    }
    return 0;
}





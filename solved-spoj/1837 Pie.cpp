#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
#include<stack>
using namespace std;
long long a[10011];
long long mx;
int N,M;
int check(long long n)
{
    int sum=0;
    for(int i=0; i<N; i++)
        sum+=a[i]/n;
    return sum;
}

void bisection(long long high)
{
    long long mid,low=0;
    int sum;
    while(low<=high)
    {
        mid=(low+high)/2;
        sum=check(mid);
        if(sum>=M)
        {
            mx=max(mid,mx);
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    return;
}

main()
{
    int tc;
    long long m,n,xx;
    double mxx;
    int i,j,k,l;
    scanf("%d",&tc);
    while(tc--)
    {
        xx=0;
        scanf("%d %d",&N,&M);
        for(i=0; i<N; i++)
        {
            scanf("%d",&k);
            a[i]=k*k*acos(-1)*10000;
            xx=max(a[i],xx);
        }
        mx=0;
        M++;
        bisection(xx);
        mxx=(double)mx/10000;
        printf("%.4lf\n",mxx);
    }
    return 0;
}

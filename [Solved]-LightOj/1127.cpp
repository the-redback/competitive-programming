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
long long a[25];
vector <long long>v;
vector <long long>vv;
void part1(int n)
{
    long long sum=0;
    v.clear();
    n=pow(2,n+1);
    int k=0;
    for(int i=0;i<n;i++)
    {
        int j=i;
        k=0;
        sum=0;
        while(j>0)
        {
            int f=j%2;
            j=j/2;
            sum+=f*a[k];
            k++;
        }
        v.push_back(sum);
    }
}

void part2(int m,int n)
{
    long long sum=0;
    vv.clear();
    n=pow(2,n-m+1);
    int k=m;
    for(int i=0;i<n;i++)
    {
        int j=i;
        k=m;
        sum=0;
        while(j>0)
        {
            int f=j%2;
            j=j/2;
            sum+=f*a[k];
            k++;
        }
        vv.push_back(sum);
    }
}

main()
{
    int tc;
    scanf("%d",&tc);
    for(int t=1;t<=tc;t++)
    {
        int i,j,k,l,n,total;
        long long sum,x;
        scanf("%d%lld",&n,&sum);
        for(i=0;i<n;i++)
            scanf("%lld",&a[i]);
        i=(n-1)/2;
        part1(i);
        part2(i+1,n-1);
        sort(v.begin(),v.end());
        vector<long long>::iterator high;
        total=0;
        for(i=0;i<vv.size();i++)
        {
            if(vv[i]<=sum)
            {
                x=sum-vv[i];
                high=upper_bound(v.begin(),v.end(),x);
                k=high-v.begin();
                total+=k;
            }
        }
        printf("Case %d: %d\n",t,total);
    }
    return 0;
}

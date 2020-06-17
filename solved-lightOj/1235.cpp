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
long a[25];
vector <long>v;
vector <long>vv;
void part1(int n)
{
    v.clear();
    n=pow(3,n+1);
    int k=0;
    for(int i=0;i<n;i++)
    {
        int j=i;
        k=0;
        int sum=0;
        while(j>0)
        {
            int f=j%3;
            j=j/3;
            sum+=f*a[k];
            k++;
        }
        v.push_back(sum);
    }
}

void part2(int m,int n)
{
    vv.clear();
    n=pow(3,n-m+1);
    int k=m;
    for(int i=0;i<n;i++)
    {
        int j=i;
        k=m;
        int sum=0;
        while(j>0)
        {
            int f=j%3;
            j=j/3;
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
        int i,j,l,n;
        long sum,k;
        scanf("%d%ld",&n,&sum);
        for(i=0;i<n;i++)
            scanf("%ld",&a[i]);
        i=(n-1)/2;
        part1(i);
        part2(i+1,n-1);
        sort(v.begin(),v.end());
        for(i=0;i<vv.size();i++)
        {
            k=sum-vv[i];
            if(binary_search(v.begin(),v.end(),k))
            {
                printf("Case %d: Yes\n",t);
                break;
            }
        }
        if(i==vv.size())
            printf("Case %d: No\n",t);
    }
    return 0;
}

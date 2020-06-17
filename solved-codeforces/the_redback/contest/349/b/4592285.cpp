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
vector<int>j;
vector<int>ret;

struct point
{
    int n;
    int x;
};
bool comp(point xx,point yy)
{
    if(xx.n==yy.n)
    {
        return xx.x<yy.x;
    }
    else
    return xx.n<yy.n;
}
main()
{
    int i,k,l,m;
    point a[11];
    point b[11];
    scanf("%d",&m);
    for(i=0;i<9;i++)
    {
        scanf("%d",&a[i].n);
        a[i].x=i+1;
        b[i].x=a[i].x;
        b[i].n=a[i].n;
    }
    sort(a,a+9,comp);
    ret.clear();
    j.clear();
    if(m<a[0].n)
    {
        puts("-1");
        return 0;
    }
    k=(m/a[0].n);
    for(i=1;i<=k;i++)
    {
        ret.push_back(a[0].x);
    }
    m-=k*a[0].n;
    while(ret.size()>=1 && m+a[0].n>=a[1].n)
    {
        for(i=8;i>=0;i--)
        {
            if(m+a[0].n>=b[i].n)
            {
                ret.pop_back();
                j.push_back(b[i].x);
                m=m+a[0].n-b[i].n;
                break;
            }
        }
    }
    while(j.size()!=0)
    {
        int k=j[j.size()-1];
        j.pop_back();
        ret.push_back(k);
    }
    if(j.size()==0 && ret.size()==0)
        puts("-1");
    else
    {
        for(i=ret.size()-1;i>=0;i--)
            printf("%d",ret[i]);
        printf("\n");
    }
    return 0;
}

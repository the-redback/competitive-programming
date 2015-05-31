#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
vector <int>v;
int array[20];
int n,f;
int visit[20]={0};

int prime(int p)
{
    if(p==2)
        return 0;
    if(p==3)
        return 0;
    if(p%2==0)
        return 1;
    for(int i=3;i*i<=p;i+=2)
    {
        if(p%i==0)
            return 1;
    }
    return 0;
}

void check(int remain)
{
    if(remain==0)
    {
        for(int i=0;i<v.size();i++)
        {
            if(i!=0)
            {
                printf(" ");
            }
            printf("%d",v[i]);
        }
        printf("\n");
        return;

    }
    for(int i=1;i<n;i++)
    {
        if(visit[i]==0)
        {
            visit[i]=1;
            if(prime(i+1+v[v.size()-1])==0)
            {
                if(v.size()+1==n)
                {
                    if(prime(i+1+v[0])==0)
                    {
                        v.push_back(i+1);
                        check(remain-1);
                        v.pop_back();
                    }
                }
                else
                {
                    v.push_back(i+1);
                    check(remain-1);
                    v.pop_back();
                }
            }
            visit[i]=0;
        }
    }
}

main()
{
    v.push_back(1);
    int i=1;
    while(~scanf("%d",&n))
    {
        if(i!=1)
            printf("\n");
        printf("Case %d:\n",i++);
        check(n-1);
    }
    return 0;
}

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector <int> v;
bool pr[2001];
int a[1000001];
int b[1000001];
void prime(int n)
{
    memset(pr,0,sizeof(pr));
    pr[0]=1;
    pr[1]=1;
    int i,j;
    for(i=4;i<n;i+=2)
        pr[i]=1;
    for(i=3;i*i<n;i++)
    {
        if(pr[i]==0)
        for(j=i*i;j<n;j+=i*2)
        {
            pr[j]=1;
        }
    }
    for(i=0;i<n;i++)
    {
        if(pr[i]==0)
            v.push_back(i);
    }
}
main()
{
    int t;
    long i,max,r,j,k,l,n;
    prime(2001);
    for(i=0;i<=1000000;i++)
        {
            l=1;
            j=0;
            k=i;
            while(k!=1 && v[j]*v[j]<=k)
            {
                r=0;
                while(k%v[j]==0)
                {
                    k=k/v[j];
                    r++;
                }
                l=l*(r+1);
                j++;
            }
            if(k!=1)
                l*=2;
            a[i]=l;
        }
        b[1]=1;
        max=1;
        for(i=2;i<=1000000;i++)
        {
            if(a[i]>=max)
            {
                b[i]=i;
                max=a[i];
            }
            else
            {
                b[i]=b[i-1];
            }
        }
    scanf("%d",&t);
    while(t--)
    {
        scanf("%ld",&n);
        printf("%ld\n",b[n]);
    }
    return 0;
}

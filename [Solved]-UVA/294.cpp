#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool p[57701];
void prime(int n)
{
    memset(p,0,sizeof(p));
    p[0]=1;
    p[1]=1;
    int i,j;
    for(i=4;i<n;i+=2)
        p[i]=1;
    for(i=3;i*i<n;i++)
    {
        if(p[i]==0)
        for(j=i*i;j<n;j+=i*2)
        {
            p[j]=1;
        }
    }
}
main()
{
    int t;
    long i,max,r,num,j,k,l,m,n;
    prime(57701);
    scanf("%d",&t);
    while(t--)
    {
        max=-1;
        scanf("%ld %ld",&m,&n);
        for(i=m;i<=n;i++)
        {
            l=1;
            j=2;
            k=i;
            while(k!=1 && j*j<=k)
            {
                while(p[j])
                {
                    if(j>51700)
                        printf("%d ",j);
                    j++;
                }
                r=0;
                while(k%j==0)
                {
                    k=k/j;
                    r++;
                }
                l=l*(r+1);
                j++;
            }
            if(k!=1)
                l*=2;
           if(max<l)
           {
               max=l;
               num=i;
           }
        }
        printf("Between %ld and %ld, %ld has a maximum of %ld divisors.\n",m,n,num,max);
    }
    return 0;
}

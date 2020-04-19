#include<cstdio>
#include <cstring>
#include <algorithm>
#include <math.h>

using namespace std;
bool a[32770];

void prime(int n)
{
    int i,j,k,l;
    memset(a,0,sizeof(a));
    a[0]=1;
    a[1]=1;
    for(i=4;i<=n;i+=2)
        a[i]=1;
    for(i=3;i*i<=n;i++)
    {
        if(a[i]==0)
            for(j=i*i;j<=n;j+=2*i)
            {
                a[j]=1;
            }
    }
}

int main()
{
    prime(32770);
    int i,j,k,n,count;
    while(scanf("%d",&n))
    {
        if(n==0)
            return 0;
        count=0;
        for(i=2;i<=n/2;i++)
        {
            while(a[i] && i<n/2)
            {
                i++;
            }
            k=n-i;
            if(!a[k])
            {
                count++;
            }
        }
        printf("%d\n",count);
    }
    return 0;

}

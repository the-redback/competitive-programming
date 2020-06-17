#include<cstdio>
#include <cstring>
#include <algorithm>
#include <math.h>

using namespace std;
bool a[1001];

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
    prime(1000);
    int i,j,k,n,count;
    while(scanf("%d",&n))
    {
        if(n==0)
            return 0;
        count=0;
        k=n;
        for(i=2;i*i<=n;i++)
        {
            j=0;
            while(a[i])
            {
                i++;
            }
            while(n%i==0)
            {
                if(j==0)
                    count++;
                n=n/i;
                j=1;
            }
        }
        if(n!=1)
            count++;
        printf("%d : %d\n",k,count);
    }
    return 0;

}

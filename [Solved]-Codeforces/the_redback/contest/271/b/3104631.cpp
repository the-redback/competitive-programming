#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
using namespace std;
bool pr[1000006];
void sieve(long n)
{
    memset(pr,0,sizeof(pr));
    long i,j,k,l;
    pr[1]=1;
    for(i=4;i<=n;i+=2)
        pr[i]=1;
    for(i=3;i*i<=n;i+=2)
    {
        if(pr[i]==0)
        {
            for(j=i*i;j<=n;j+=2*i)
                pr[j]=1;
        }
    }
}


main()
{
    int a[501][501],b[501],c[501];
    int i,j,k,m,n,min;
    sieve(1000006);
    scanf("%d %d",&m,&n);
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    for(i=0;i<m;i++)
    {
        b[i]=0;
        for(j=0;j<n;j++)
        {
            k=a[i][j];
            while(pr[k])
            {
                k++;
            }
            b[i]+=k-a[i][j];
        }
    }
    for(i=0;i<n;i++)
    {
        c[i]=0;
        for(j=0;j<m;j++)
        {
            k=a[j][i];
            while(pr[k])
            {
                k++;
            }
            c[i]+=k-a[j][i];
        }
    }
    min=b[0];
    for(i=0;i<m;i++)
        if(b[i]<min)
        {
            min=b[i];
        }
    for(i=0;i<n;i++)
        if(c[i]<min)
        {
            min=c[i];
        }
    printf("%d\n",min);

    return 0;
}

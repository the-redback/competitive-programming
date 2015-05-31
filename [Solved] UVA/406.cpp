#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
int a[1001];
void prime(void)
{
    int i,j;
    a[0]=1;
    a[1]=0;
    memset(a,0,sizeof(a));
    for(i=4;i<=1000;i+=2)
    {
        a[i]=1;
    }
    for(i=3;i*i<=1000;i++)
    {
        if(a[i]==0)
        {
            for(j=i*i;j<=1000;j+=2*i)
            {
                a[j]=1;
            }
        }
    }
}

main()
{
    int b[1001];
    b[0]=0;
    int c[1001];
    c[0]=0;
    int n,i,j=1,t,m,k;
    prime();
    for(i=1;i<=1000;i++)
    {
        if(a[i]==0)
        {
            b[j++]=i;
            c[i]=c[i-1]+1;
        }
        else
            c[i]=c[i-1];
    }
    while(scanf("%d %d",&n,&t)==2)
    {
        k=c[n];
        if(k%2==1)
        {
            j=ceil(k/2.0);
            i=j-t+1;
            m=j+t-1;
        }
        else
        {
            j=k/2;
            i=j-t+1;
            m=j+t;
        }
        printf("%d %d:",n,t);
        if(i<1)
            i=1;
        if(m>k)
            m=k;
        while(i<=m)
        {
            printf(" %d",b[i]);
            i++;
        }
        printf("\n\n");
    }
    return 0;
}

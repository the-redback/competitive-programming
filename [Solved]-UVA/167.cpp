#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int b[10][10];
int a[10],I=1,n=8,sum;

int check(int k,int j)
{
    int i;
    for(i=1;i<k;i++)
    {
        if(a[i]==j)
            return 0;
        if(abs(a[i]-j)==abs(k-i))
            return 0;
    }
    return 1;
}


int call(int k)
{
    int i,s,j;
    if(k>=n+1)
    {
        s=0;
        for(i=1;i<=n;i++)
        {
            j=a[i];
            s+=b[i][j];
        }
        if(sum<s)
            sum=s;

    }
    for(i=1;i<=n;i++)
    {
        if(check(k,i))
        {
            a[k]=i;
            call(k+1);
        }
    }
}

main()
{
    n=8;
    int i,j,k,t;
    scanf("%d",&t);
    while(t--)
    {
        for(i=1;i<=8;i++)
            for(j=1;j<=8;j++)
                scanf("%d",&b[i][j]);
        sum=0;
        call(1);
        printf("%5d\n",sum);
    }
    return 0;
}

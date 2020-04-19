#include <stdio.h>
#include <math.h>

int div(int n)
{
    int count=0;
    int k,i,j=sqrt(n);
    for(i=1;i<=j;i++)
    {
        k=n/i;
        if(i*k==n && i!=k)
        {
            count+=2;
        }
        else if(i*k==n)
        {
            count++;
        }
    }
    return count;
}

main()
{
    int i,j,n,t,temp;
    int a[1001],b[1001];
    a[1]=1;
    b[1]=1;
    for(i=2;i<=1000;i++)
    {
        a[i]=i;
        b[i]=div(i);
    }
    for(i=1;i<1000;i++)
    {
        for(j=1;j<=1000-i;j++)
        {
            if(b[j]>b[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
                temp=b[j];
                b[j]=b[j+1];
                b[j+1]=temp;
            }
            else if(b[j]==b[j+1] && a[j]<a[j+1] )
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
                temp=b[j];
                b[j]=b[j+1];
                b[j+1]=temp;
            }
        }
    }
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d",&n);
        printf("Case %d: %d\n",i,a[n]);
    }
    return 0;
}

#include <cstdio>
#include <math.h>
int a[1000001];
int check(int n)
{
    int m,i;
    if(n==0)
    return 0;
    if(n==1)
    return 0;
    if(n==2)
    return 1;
    if(n%2==0)
    return 0;
    for(i=3;i*i<=n;i+=2)
    {
        if(n%i==0)
        {
            return 0;
        }
    }
    return 1;

}

main()
{
    int i,j,n,t,t1,t2,count;
    a[0]=0;
    for(i=1;i<=1000000;i++)
    {
        if(i%2==0 && i!=2)
        {
            a[i]=a[i-1]+0;
        }
        else if(check(i)==1)
        {
            n=0;
            j=i;
            while(j>0)
            {
                n+=j%10;
                j=j/10;
            }
            if(check(n)==1)
            {
                a[i]=a[i-1]+1;
            }
            else
            {
                a[i]=a[i-1]+0;
            }
        }
        else
        {
            a[i]=a[i-1]+0;
        }
    }
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&t1,&t2);
        if(t1>t2)
        {
            i=t1;
            t1=t2;
            t2=i;
        }
        count=a[t2]-a[t1-1];
        printf("%d\n",count);
    }
    return 0;
}

#include<stdio.h>
#include<math.h>
#include <string.h>
int pr[105001];
int prime(long n)
{
    long i;
    if(n==1)
        return 1;
    if(n==2)
        return 0;
    if(n%2==0)
        return 1;
    for(i=3;i*i<=n;i+=2)
    {
        if(n%i==0)
            return 1;
    }
    return 0;
}
void sieve(int n)
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
    j=0;
    for(i=1;i<=105000;i++)
    {
        if(pr[i]==0)
        pr[j++]=i;
    }
}
int check(long n)
{
    int sum=0;
    while(n!=0)
    {
        sum+=n%10;
        n/=10;
    }
    return sum;
}

main()
{
    sieve(105000);
    long i,j,k,m,sum,n;
    int t,test;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%ld",&n);
        sum=-1;
        for(i=n+1;;i++)
        {
            m=check(i);
            sum=0;
            t=0;
            j=sqrt(i);
            k=i;
            if(prime(i)==0)
                continue;
            while(k!=1 && pr[t]<=j )
            {
                while(k%pr[t]==0)
                {
                    k=k/pr[t];
                    sum+=check(pr[t]);
                }
                t++;
            }
            if(k!=1)
                sum+=check(k);
            if(sum==m)
            {
                printf("%ld\n",i);
                break;
            }
        }

    }
    return 0;
}

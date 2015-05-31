#include<stdio.h>
#include<math.h>
long p;
long check(long m,long n)
{
    int sum;
    if(n==0)
        return 1;
    if(n%2==0)
    {
        sum=check(m,n/2);
        return ((sum%p)*(sum%p))%p;
    }
    else
    {
        sum=check(m,n-1);
        return ((m%p)*(sum%p))%p;
    }
}

int main()
{
    long m,n,sum;
    while(scanf("%ld %ld %ld",&m,&n,&p)==3)
    {
        sum=check(m,n);
        printf("%ld\n",sum);
    }
    return 0;
}

#include <stdio.h>
#include <string.h>

main()
{
    char a[100000];
    long long n,sum,mod;
    int i,j,t;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%s %lld",&a,&n);
        if(n<0)
            n=-1*n;
        sum=0;
        for(j=0;a[j]!='\0';j++)
        {
            if(a[j]=='+' || a[j]=='-')
            continue;

            sum=sum*10+a[j]-48;
            sum=sum%n;
        }
        if(sum==0)
        {
            printf("Case %d: divisible\n",i);
        }
        else
        {
            printf("Case %d: not divisible\n",i);
        }
    }
    return 0;

}

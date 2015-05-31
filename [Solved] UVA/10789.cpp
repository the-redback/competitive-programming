#include <cstdio>
#include <cstring>
#include <algorithm>
int prime(int n)
{
    int i;
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
    int n,t,l,i,j,c;
    int b[123];
    char a[5000];
    scanf("%d",&t);
    getchar();
    for(j=1;j<=t;j++)
    {
        for(i=0;i<=122;i++)
        {
            b[i]=0;
        }
        gets(a);
        l=strlen(a);
        std::sort(a,a+l);
        for(i=0;i<=l;i++)
        {
            n=a[i];
            b[n]++;
        }
        for(i=48;i<=122;i++)
        {
            if(prime(b[i])==0)
            {
                b[i]=0;
            }
        }
        printf("Case %d: ",j);
        c=0;
        for(i=48;i<=122;i++)
        {
            if(b[i]!=0)
            {
                printf("%c",i);
                c=1;
            }
        }
        if(c==0)
        {
            printf("empty");
        }
        printf("\n");
    }
}

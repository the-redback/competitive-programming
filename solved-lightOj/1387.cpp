#include <cstdio>
#include <cstring>

main()
{
    long m;
    long long sum;
    int i,t,n;
    char a[7];
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d",&n);
        getchar();
        sum=0;
        printf("Case %d:\n",i);
        while(n--)
        {
            scanf("%s",&a);
            if(strcmp(a,"donate")==0)
            {
                scanf("%ld",&m);
                sum+=m;
            }
            else if(strcmp(a,"report")==0)
            {
                printf("%lld\n",sum);
            }
        }
    }
    return 0;
}

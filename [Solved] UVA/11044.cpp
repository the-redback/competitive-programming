#include <cstdio>
#include <cstring>
main()
{
    int a,b,t;
    int sum;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&a,&b);
        sum=((int)(a/3))*((int)(b/3));
        printf("%d\n",sum);
    }
    return 0;
}

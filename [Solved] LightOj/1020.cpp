#include <stdio.h>
#include <string.h>
main()
{
    char a[10];
    long n;
    int i,t;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%ld %s",&n,&a);
        printf("Case %d: ",i);
        if(a[0]=='A')
        {
            if((n-1)%3==0)
                puts("Bob");
            else
                puts("Alice");
        }
        else if(a[0]=='B')
        {
            if(n%3==0)
                puts("Alice");
            else
                puts("Bob");
        }
    }
    return 0;
}

#include <stdio.h>
main()
{
    int m,n;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        printf("%d\n",(n*m)-1);
    }
    return 0;
}

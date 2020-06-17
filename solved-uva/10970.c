#include <stdio.h>
main()
{
    int m,n,a;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        a=(n*m)-1;
        printf("%d\n",a);
    }
    return 0;
}

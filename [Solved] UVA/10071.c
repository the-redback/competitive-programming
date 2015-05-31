#include <stdio.h>
main()
{
    int v,a,s;
    while(scanf("%d%d",&v,&a)!=EOF)
    {
        s=2*v*a;
        printf("%d\n",s);
    }
    return 0;
}

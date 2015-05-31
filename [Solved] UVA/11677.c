#include <stdio.h>

main()
{
    int a,b,c,d,e,f,g;

    while(scanf("%d%d%d%d",&a,&b,&c,&d)!=EOF)
    {
        if(a==0 && b==0 && c==0 && d==0 )
        {
            break;
        }
        e=(a*60)+b;
        f=(c*60)+d;
        if(f>e)
        {
            printf("%d\n",(f-e));
        }
        else
        {
            g=1440-(e-f);
            printf("%d\n",g);
        }
    }
    return 0;
}

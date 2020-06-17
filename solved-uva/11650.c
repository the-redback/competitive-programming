#include <stdio.h>

main()
{
    char ch;
    int h,m,h1,m1,test,i;
    scanf("%d",&test);
    for(i=0;i<test;i++)
    {
        scanf("%d:%d",&h,&m);
        if(h>=12)
        {
            h=h-12;
        }
        if(m==0)
        {
            m1=0;
            h1=12-h;
            if(h1==0)
            {
                h1=12;
            }
        }
        else
        {
            m1=60-m;
            h1=11-h;
            if(h1==0)
            {
                h1=12;
            }
        }
        printf("%02d:%02d\n",h1,m1);
    }
    return 0;
}

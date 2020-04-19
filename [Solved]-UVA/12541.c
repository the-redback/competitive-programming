#include <stdio.h>

main()
{
    int s[101],dd,mm,yy,t,i,max,low,m,l;
    char a[101][16];
    scanf("%d",&t);
    getchar();
    for(i=0;i<t;i++)
    {
        scanf("%s%d%d%d",a[i],&dd,&mm,&yy);
                s[i]=(yy*365)+(mm*30)+dd;
    }
    max=s[0];
    low=s[0];
    m=0;
    l=0;
    for(i=0;i<t;i++)
    {
        if(max<s[i])
        {
            max=s[i];
            m=i;
        }
        if(low>s[i])
        {
            low=s[i];
            l=i;
        }
    }
    printf("%s\n%s\n",a[m],a[l]);
    return 0;
}

#include <stdio.h>

main()
{
    int a[]={00,01,81};
    int b[]={0,1,2025,3025,9801};
    int c[]={0,1,88209,494209,998001};
    int d[]={0,1,4941729,7441984,24502500,25502500,52881984,60481729,99980001};
    int i,n,t;
    while(scanf("%d",&n)==1)
    {
        if(n==2)
        {
            for(i=0;i<3;i++)
                printf("%02d\n",a[i]);
        }
        else if(n==4)
        {
            for(i=0;i<5;i++)
                printf("%04d\n",b[i]);
        }
        else if(n==6)
        {
            for(i=0;i<5;i++)
                printf("%06d\n",c[i]);
        }
        else if(n==8)
        {
            for(i=0;i<9;i++)
                printf("%08d\n",d[i]);
        }
    }
    return 0;
}

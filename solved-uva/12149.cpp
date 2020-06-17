#include <stdio.h>

main()
{
    int a[101];
    a[0]=0;
    a[1]=1;
    int i,n;
    for(i=2;i<=100;i++)
    {
        a[i]=(i*i)+a[i-1];
    }
    while(scanf("%d",&n))
    {
        if(n==0)
        {
            break;
        }
        printf("%d\n",a[n]);
    }
    return 0;
}

#include <stdio.h>
#include <string.h>

main()
{
    int a[1010];
    int i,j,k,l;
    memset(a,0,sizeof(a));
    scanf("%d %d",&k,&l);
    while(l--)
    {
        scanf("%d %d",&i,&j);
        a[i]=1;
        a[j]=1;
    }
    printf("%d\n",k-1);
    for(i=1;i<=k;i++)
    {
        if(a[i]==0)
        {
            j=i;
            break;
        }
    }
    for(i=01;i<=k;i++)
    {
        if(i!=j)
        {
            printf("%d %d\n",j,i);
        }
    }
    return 0;
}

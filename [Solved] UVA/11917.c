#include <stdio.h>
#include <string.h>

main()
{
    int t,i,j,k,n,d;
    int ai[1000];
    char a[1000][25];
    char c[25];
    scanf("%d",&t);
    for(j=1;j<=t;j++)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%s %d",&a[i],&ai[i]);
        }
        scanf("%d",&d);
        scanf("%s",&c);
        for(i=0;i<n;i++)
        {
            if(strcmp(a[i],c)==0)
            {
                break;
            }
        }
        if(i<n && ai[i]<=d)
        {
            printf("Case %d: Yesss\n",j);
        }
        else if(i<n && ai[i]<=(d+5))
        {
            printf("Case %d: Late\n",j);
        }
        else
        {
            printf("Case %d: Do your own homework!\n",j);
        }
    }
    return 0;
}

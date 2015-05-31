#include <cstdio>
#include <cstring>

main()
{
    char a[15],b[15];
    int i,j,l,t,k;
    scanf("%d",&t);
    getchar();
    for(i=1;i<=t;i++)
    {
        gets(a);
        l=strlen(a);
        for(j=l-1,k=0;j>=0;j--,k++)
        {
            b[k]=a[j];
        }
        b[k]='\0';
        if(strcmp(a,b)==0)
        {
            printf("Case %d: Yes\n",i);
        }
        else
        {
            printf("Case %d: No\n",i);
        }
    }
    return 0;
}

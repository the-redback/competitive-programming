#include <cstdio>
#include <cstring>

main()
{
    char a[101],b[101];
    int l,i,j,m,t,k;
    scanf("%d",&t);
    getchar();
    for(m=1;m<=t;m++)
    {
        gets(a);
        gets(b);
        l=strlen(b);
        k=strlen(a);
        for(i=0;i<k;i++)
        {
            if(a[i]>='A' && a[i]<='Z')
            {
                a[i]+=32;
            }
        }
        for(i=0;i<l;i++)
        {
            if(b[i]>='A' && b[i]<='Z')
            {
                b[i]+=32;
            }
        }
        for(i=0;i<k;i++)
        {
            if(a[i]==' ')
                {
                    continue;
                }
            for(j=0;j<l;j++)
            {

                if(a[i]==b[j])
                {
                    b[j]='0';
                    break;
                }
            }
            if(j==l)
            {
                break;
            }
        }
        if(i==k)
        {
            printf("Case %d: Yes\n",m);
        }
        else
        {
            printf("Case %d: No\n",m);
        }
    }
    return 0;
}

#include <stdio.h>
#include <string.h>

main()
{
    char a[201],b[201];
    long long n;
    int i,t,j,l,k,m;
    scanf("%d",&t);
    getchar();
    for(k=1;k<=t;k++)
    {
        gets(a);
        l=strlen(a);
        j=0;
        n=0;
        printf("Case %d: ",k);
        for(i=0;i<l;i++)
        {
            if(a[i]>='A' && a[i]<='Z')
            {
                b[j]=a[i];
                j++;
            }
            else if(a[i]>='0' && a[i]<='9')
            {
                n=(n*10)+a[i]-48;
            }
            if((a[i]>='0' && a[i]<='9' && a[i+1]>='A' && a[i+1]<='Z')||(a[i]>='0' && a[i]<='9' && a[i+1]=='\0'))
            {
                b[j]='\0';
                for(m=0;m<n;m++)
                {
                    printf("%s",b);
                }
                j=0;
                n=0;
            }
        }
        printf("\n");
    }
    return 0;
}

#include <stdio.h>
#include <string.h>

main()
{
    char a[10000];
    int i,l,count;

    while(gets(a))
    {
        count=0;
        l=strlen(a);

        for(i=0;i<=l;i++)
        {
            if(a[i]==' ' ||a[i]==',' ||a[i]=='.'||a[i]==';' ||a[i]=='!'||a[i]=='\0'|| a[i]>='0' && a[i]<='9')
            {
                if(a[i-1]>='A'&& a[i-1]<='Z' || a[i-1]>='a' && a[i-1]<='z')
                {
                    count++;
                }
            }
        }
        printf("%d\n",count);

    }
    return 0;
}

#include <stdio.h>
#include <string.h>

main()
{
    char a[1000],b[1000];
    int i,j,l;
    while(gets(a))
    {
        l=strlen(a);
        for(i=0;i<l;i++)
        {
            b[i]=a[i]-7;
        }
        b[i]='\0';
        printf("%s\n",b);
    }
    return 0;
}

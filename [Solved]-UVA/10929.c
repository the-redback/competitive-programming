#include <stdio.h>
#include <string.h>

main()
{
    int b,c,i;
    char a[100000];
    while(scanf("%s",&a))
    {
        if(a[0]=='0' && a[1]=='\0')
        {
            break;
        }
        b=0;
        for(i=0;a[i];i++)
        {
            b=b*10+a[i]-48;
            c=b%11;
            b=c;
        }
        if(b==0)
        {
            printf("%s is a multiple of 11.\n",a);
        }
        else
        {
            printf("%s is not a multiple of 11.\n",a);
        }
    }
    return 0;
}

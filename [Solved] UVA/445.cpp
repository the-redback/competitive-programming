#include <stdio.h>
#include <string.h>
main()
{
    char a[135];
    int i,j,k,l,flag,x;
    while(gets(a))
    {
        if(a[0]=='\n')
        {
            puts("");
            continue;
        }
        l=strlen(a);
        flag=0;
        for(i=0;i<l;i++)
        {
            if(a[i]>='0' && a[i]<='9')
                flag+=a[i]-'0';
            else if(a[i]=='b')
            {
                for(j=0;j<flag;j++)
                    printf(" ");
                flag=0;
            }
            else if(a[i]>='A' && a[i]<='Z' || a[i]=='*')
            {
                for(j=0;j<flag;j++)
                    printf("%c",a[i]);
                flag=0;
            }
            else if(a[i]=='!')
            {
                puts("");
                flag=0;
            }
        }
        puts("");
    }
    return 0;
}

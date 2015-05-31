#include <stdio.h>
#include <string.h>

int mod(char a[])
{
    int b,i;
    b=0;
    for(i=0;a[i]!='\0';i++)
    {
        b=(b*10)+a[i]-48;
        b=b%17;
    }
    return b;
}

main()
{
    int l,i,j,k;
    char a[1000000];
    while(gets(a))
    {
        if(strcmp(a,"0")==0)
        {
            break;
        }
        k=mod(a);
        if(k==0)
        {
            printf("1\n");
        }
        else
        {
            printf("0\n");
        }
    }
    return 0;
}

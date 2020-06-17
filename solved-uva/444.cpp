#include <stdio.h>
#include <string.h>

main()
{
    char a[1000],b[1000];
    int i,j,l,k;
    while(gets(a))
    {
        if(a[0]>='0'&&a[0]<='9')
        {
            j=0;
            l=0;
            k=strlen(a);
            for(i=k-1;i>=0;i--)
            {
                j=j*10+a[i]-48;
                if(j> 64 || j==32 ||j==33|| j==44|| j==46|| j==58|| j==59|| j==63)
                {
                    b[l]=j;
                    l++;
                    j=0;
                }
            }
            b[l]='\0';
        }
        else
        {
            l=0;
            k=strlen(a);
            for(i=k-1;i>=0;i--)
            {
                j=a[i];
                while(j>0)
                {
                    b[l]=j%10+48;
                    j=j/10;
                    l++;
                }
            }
            b[l]='\0';
        }
        printf("%s\n",b);
    }
    return 0;
}

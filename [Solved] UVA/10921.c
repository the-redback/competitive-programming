#include <stdio.h>
#include <string.h>

main()
{
    int i,j,l;

    char a[32];

    while(gets(a))
    {
        l=strlen(a);

        for(i=0;i<l;i++)
        {
            if(a[i]=='0')
            {
                printf("0");
            }
            else if( a[i]=='1')
            {
                printf("1");
            }
            else if(a[i]=='-')
            {
                printf("%c",a[i]);
            }
            else if(a[i]>=65 && a[i]<=67)
            {
                printf("2");
            }
            else if(a[i]>=68 && a[i]<=70)
            {
                printf("3");
            }
            else if(a[i]>=71 && a[i]<=73)
            {
                printf("4");
            }
            else if(a[i]>=74 && a[i]<=76)
            {
                printf("5");
            }
            else if(a[i]>=77 && a[i]<=79)
            {
                printf("6");
            }
            else if(a[i]>=80 && a[i]<=83)
            {
                printf("7");
            }
            else if(a[i]>=84 && a[i]<=86)
            {
                printf("8");
            }
            else if(a[i]>=87 && a[i]<=90)
            {
                printf("9");
            }
        }
                printf("\n");
    }
    return 0;

}

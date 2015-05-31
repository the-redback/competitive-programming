#include <stdio.h>
#include <string.h>

main()
{
    char a[1000],b[1100];
    int i,j,k,l;
    j=1;

    while(gets(a))
    {
        l=strlen(a);
        for(i=0,k=0;i<l;i++)
        {
            if(a[i]==34)
            {
                if( j%2!=0)
                {
                    printf("%c%c",96,96);
                    j++;
                }
                else if(j%2==0)
                {
                    printf("%c%c",39,39);
                    j++;
                }
            }
            else
            {
                printf("%c",a[i]);
            }
        }
        printf("\n");
    }
    return 0;
}


#include <stdio.h>
#include <string.h>

main()
{
    char a[21];
    int i,j,k,l;

    while(gets(a))
    {
        j=0;
        l=strlen(a);
        for(i=0;i<l;i++)
        {
            if(a[i]=='B' || a[i]=='P' ||a[i]=='F' || a[i]=='V')
            {
                if(j!=1)
                {
                    printf("1");
                    j=1;
                }
            }
            else if(a[i]=='C'||a[i]=='G' || a[i]=='J'||a[i]=='K'||a[i]=='Q'||a[i]=='S'||a[i]=='X'||a[i]=='Z')
            {
                if(j!=2)
                {
                    printf("2");
                    j=2;
                }
            }
            else if(a[i]=='D' || a[i]=='T')
            {
                if(j!=3)
                {
                    printf("3");
                    j=3;
                }
            }
            else if(a[i]=='L')
            {
                if(j!=4)
                {
                    printf("4");
                    j=4;
                }
            }
            else if(a[i]=='M'||a[i]=='N')
            {
                if(j!=5)
                {
                    printf("5");
                    j=5;
                }
            }
            else if(a[i]=='R')
            {
                if(j!=6)
                {
                    printf("6");
                    j=6;
                }
            }
            else
            {
                j=7;
            }
        }
        printf("\n");
    }
    return 0;
}

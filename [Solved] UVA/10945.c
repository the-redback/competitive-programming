#include <stdio.h>
#include <string.h>

main()
{
    char a[10000],b[10000],c[5]="DONE";
    int i,j,l;


    while(gets(a))
    {
        if(strcmp(a,c)==0)
        {
            break;
        }
        l=strlen(a);
        for(i=0;i<l;i++)
        {
            if(a[i]>='A' && a[i]<='Z')
            {
                a[i]=a[i]+32;
            }
        }
        j=0;
        for(i=0;i<l;i++)
        {
            if(a[i]>='a' && a[i]<='z')
            {
                b[j]=a[i];
                j++;
            }
        }
        b[j]='\0';
        a[j]='\0';
        l=j;
        j--;
        for(i=0;i<l;i++)
        {
            a[j]=b[i];
            j--;
        }

        if(strcmp(a,b)==0)
        {
            printf("You won't be eaten!\n");
        }
        else
        {
            printf("Uh oh..\n");
        }
    }

    return 0;
}


#include <stdio.h>
#include <string.h>

main()
{
    char a[1001];
    int i,k,j,l;
    while(gets(a))
    {
        if(strcmp(a,"*")==0)
        return 0;

        k=a[0];
        l=strlen(a);
        for(i=0;i<l;i++)
        {
            if(a[i]==' ')
            {
                if(a[i+1]==k || a[i+1]==k-32 ||a[i+1]==k+32 )
                continue;

                else
                break;
            }
        }
        if(i==l)
        {
            printf("Y\n");
        }
        else
        {
            printf("N\n");
        }
    }
    return 0;
}

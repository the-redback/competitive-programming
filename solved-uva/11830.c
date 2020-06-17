#include <stdio.h>
#include <string.h>

main()
{
    char a[105];
    char c;
    int n,i,j,l;
    while(scanf("%c",&c)!=EOF)
    {
        getchar();
        gets(a);
        if (c=='0' && a[0]=='0' && a[1]=='\0' )
        {
            break;
        }
        l=strlen(a);
        for(i=0,j=0;i<l;i++)
        {
            if(a[i]=='0' && j==0);

            else if(a[i]!=c)
            {
                printf("%c",a[i]);
                j++;
            }
        }
        if( j == 0)
        {
            printf("0");
        }
        printf("\n");
    }
    return 0;
}

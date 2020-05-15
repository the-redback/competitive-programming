#include <stdio.h>


main()
{
    char a[51],b[51];
    int i,j=0,k;
    gets(a);
    gets(b);
    for(i=0;b[i]!='\0';i++)
    {
        if(a[j]==b[i])
        {
            j++;
        }
    }
    j++;
    printf("%d\n",j);
    return 0;
}

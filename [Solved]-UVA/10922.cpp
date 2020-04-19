#include <stdio.h>
#include <string.h>

main()
{
    char a[1001];
    int n,i,j,m,count;
    while(gets(a))
    {
        if(strcmp(a,"0")==0)
        return 0;
        n=0;

        for(i=0;a[i]!='\0';i++)
            n=n+a[i]-48;

            count=1;
            while(n>9)
            {
                i=0;
                while(n>0)
                {
                    i=i+(n%10);
                    n=n/10;
                }
                n=i;
                count++;
            }
        if(n==9)
        {
            printf("%s is a multiple of 9 and has 9-degree %d.\n",a,count);
        }
        else
        {
            printf("%s is not a multiple of 9.\n",a);
        }
    }
    return 0;
}

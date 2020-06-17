#include <stdio.h>
#include <string.h>
const int max=1000000;
main()
{
    char a[max],b[max];
    int i,j,k,l,last,count;
    while(gets(a))
    {
        l=0;
        count=1;
        while(count!=0)
        {
            count=0;
            last=0;
            j=0;
            for(i=0;a[i]!='\0';i++)
            {
                if(a[i]==' ')
                {
                    if(last==0)
                    {
                        last=1;
                        b[j]=' ';
                        j++;
                    }

                    else
                    {
                        last=0;
                        count=1;
                    }
                }
                else
                {
                    last=0;
                    b[j]=a[i];
                    j++;
                }
            }
            if(count==1)
            l++;
            b[j]='\0';
            strcpy(a,b);

        }
        printf("%d\n",l);
    }
    return 0;
}

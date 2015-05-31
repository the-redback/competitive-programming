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
        for(i=0,k=0;i<=l;i++)
        {
            if(a[i]!=34)
            {
                b[k]=a[i];
                k++;
            }
            else if(a[i]==34 && j%2!=0)
            {
                b[k]=96;
                b[k+1]=96;
                j++;
                k+=2;
            }
            else if(a[i]==34 && j%2==0)
            {
                b[k]=39;
                b[k+1]=39;
                j++;
                k+=2;
            }
        }
        printf("%s\n",b);
    }
    return 0;
}

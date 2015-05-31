#include <stdio.h>
#include <string.h>

main()
{
    char a[5000],b[1000];
    int i,j,k,l,m,n;
    while(gets(a))
    {
        j=0;
        k=0;
        l=strlen(a);
        for(i=0;i<=l;i++)
        {
            if(a[i]==' '||a[i]=='\0')
            {
                m=j;
                j--;
                for( n=0;n<m;k++,j--,n++)
                {
                    a[k]=b[j];
                }
                j=0;
                a[k]=a[i];
                k++;
            }
            else
            {
                b[j]=a[i];
                j++;
            }
        }
        printf("%s\n",a);
    }
    return 0;
}

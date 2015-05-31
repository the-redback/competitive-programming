#include <stdio.h>
#include <string.h>

main()
{
    char a[10000];
    int l,i,n,t,j,c[30],max;
    for(t=0;t<30;t++)
    {
        c[t]=0;
    }
    scanf("%d",&n);
    getchar();
    for(t=0;t<n;t++)
    {
        gets(a);
        l=strlen(a);
        for(i=0;i<l;i++)
        {
            if(a[i]>='a' && a[i]<='z')
            {
               j=a[i]-97;
               c[j]++;
            }
            if(a[i]>='A' && a[i]<='Z')
            {
               j=a[i]-65;
               c[j]++;
            }
        }
    }
    for(t=0;t<30;t++)
    {
        max=0;
        //j=0;
        for(i=0;i<30;i++)
        {
            if(c[i]>max)
            {
                max=c[i];
                j=i;
            }
        }
        if(max!=0)
        {
            printf("%c %d\n",j+65,max);
            c[j]=0;
        }
    }
    return 0;
}

#include <stdio.h>
#include <string.h>
char a[1000000],b[1000000],c[1000000];
main()
{
    int i,lc,j,ka,kb,la,lb;

    while(gets(c))
    {
        lc=strlen(c);
        j=0;
        ka=0;
        kb=0;
        for(i=0;i<lc;i++)
        {
            if(c[i]!=' ' && j==0)
            {
                a[ka]=c[i];
                ka++;
            }
            else if(c[i]!=' ' && j==1)
            {
                b[kb]=c[i];
                kb++;
            }
            else if(c[i]==' ')
            {
                j=1;
            }
        }
        a[ka]='\0';
        b[kb]='\0';
        i=0;
        la=ka;
        lb=kb;
        for(j=0;j<lb;j++)
        {
            if(a[i]==b[j])
            {
                i++;
            }
        }
        if(i==la)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
    return 0;
}

#include <stdio.h>
#include <string.h>
char a[100000000];
char b[100000000];
void work(char b[])
{
    char c[4];
    int i,l;
    l=strlen(b);
    if(l==1 || b[0]=='e' || b[0]=='E' || b[0]=='a' || b[0]=='A' || b[0]=='i' || b[0]=='I' || b[0]=='o' || b[0]=='O' || b[0]=='u' || b[0]=='U' )
    {
        strcat(b,"ay");
    }
    else
    {
        c[0]=b[0];
        c[1]='\0';
        for(i=0; i<l; i++)
        {
            b[i]=b[i+1];
        }
        strcat(c,"ay");
        strcat(b,c);
    }
}

main()
{
    int i,j,k;
    while(gets(a))
    {
        j=0;
        k=strlen(a);
        b[0]='\0';
        for(i=0; i<=k; i++)
        {
            if(a[i]>='a' && a[i]<='z' || a[i]>='A'&& a[i]<='Z')
            {
                b[j]=a[i];
                j++;
            }
            else
            {
                b[j]='\0';
                if(j!=0)
                {
                    work(b);
                    j=0;
                    printf("%s",b);
                }
                if(a[i]!='\0')
                {
                    printf("%c",a[i]);
                }
            }
        }
        printf("\n");
    }
    return 0;
}

#include <stdio.h>
#include <string.h>

main()
{
    char a[101];
    char aa[101];
    char b[101];
    char b1[101];
    char b2[101];
    char b3[101];
    char b4[101];
    int ai[4];
    int i,j,m,t;
    scanf("%d",&t);
    getchar();
    while(t--)
    {
        gets(a);
        gets(b);
        j=0;
        m=0;
        for(i=0;a[i]!='\0';i++)
        {
            if(a[i]!='>'&& a[i]!='<')
            {
                aa[j]=a[i];
                j++;
            }
            else
            {
                ai[m]=i;
                m++;
            }
        }
        aa[j]='\0';
        j=0;
        for(i=0;b[i]!='\0';i++)
        {
            if(b[i]=='.'&&b[i+1]=='.'&&b[i+2]=='.')
            {
                break;
            }
            else
            {
                b[j]=b[i];
                j++;
            }
        }
        b[j]='\0';
        j=0;
        for(i=ai[0]+1;i<ai[1];i++)
        {
            b1[j]=a[i];
            j++;
        }
        b1[j]='\0';
        j=0;
        for(i=ai[1]+1;i<ai[2];i++)
        {
            b2[j]=a[i];
            j++;
        }
        b2[j]='\0';
        j=0;
        for(i=ai[2]+1;i<ai[3];i++)
        {
            b3[j]=a[i];
            j++;
        }
        b3[j]='\0';
        j=0;
        for(i=ai[3]+1;a[i]!='\0';i++)
        {
            b4[j]=a[i];
            j++;
        }
        b4[j]='\0';
        strcat(b,b3);
        strcat(b,b2);
        strcat(b,b1);
        strcat(b,b4);
        printf("%s\n%s\n",aa,b);
    }
    return 0;
}

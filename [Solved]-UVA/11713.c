#include <stdio.h>
#include <string.h>

int check(char a[],char b[])
{
    char c[22],d[22];
    int l,k,i,j;
    l=strlen(a);
    k=strlen(b);
    if(l!=k)
    {
        return -1;
    }
    else if(l==k)
    {
        for(i=0,j=0;i<=l;i++)
        {
            if(a[i]=='a' || a[i]=='e' ||a[i]=='i' || a[i]=='o' || a[i]=='u'|| a[i]=='A' || a[i]=='E' ||a[i]=='I' || a[i]=='O' || a[i]=='U')
                ;
            else
            {
                c[j]=a[i];
                j++;
            }
        }
        for(i=0,j=0;i<=k;i++)
        {
            if(b[i]=='a' || b[i]=='e' ||b[i]=='i' || b[i]=='o' || b[i]=='u'|| b[i]=='A' || b[i]=='E' ||b[i]=='I' || b[i]=='O' || b[i]=='U')
            ;
            else
            {
                d[j]=b[i];
                j++;
            }
        }
        if(strcmp(c,d)==0)
        {
            return 1;
        }
        else if(strcmp(c,d)!=0)
        {
            return -1;
        }


    }

}

main()
{
    char a[22],b[22];
    int i,n;
    scanf("%d",&n);
    getchar();
    for(i=0;i<n;i++)
    {
        gets(a);
        gets(b);
    if(check(a,b)==-1)
    {
        printf("No\n");
    }
    else if(check(a,b)==1)
    {
        printf("Yes\n");
    }
    }
    return 0;
}

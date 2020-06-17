#include <stdio.h>
#include <string.h>

int check(char a[],char b[])
{
    char c[22];
    int i,j,l=strlen(a);

    for(i=0,j=0;i<=l;i++)
    {
        if(a[i]!=' ')
        {
            c[j]=a[i];
            j++;
        }
    }
    for(i=0;i<=l;i++)
    {

        if(strcmp(c,b)!=0 && a[i]==' ')
        {
            return -1;
        }
        else if(a[i]==' ')
        {
            return 1;
        }

    }

    if(strcmp(a,b)==0)
    {
        return 0;
    }
    else if(strcmp(a,b)!=0)
    {
        return -1;
    }

}

main()
{
    char a[22],b[22],n,i;
    scanf("%d",&n);
    getchar();
    for(i=0;i<n;i++)
    {
        gets(a);
        gets(b);

    if(check(a,b)==1)
    {
        printf("Case %d: Output Format Error\n",i+1);
    }
    else if(check(a,b)==0)
    {
        printf("Case %d: Yes\n",i+1);
    }
    else if(check(a,b)==-1)
    {
        printf("Case %d: Wrong Answer\n",i+1);
    }
    }
    return 0;
}

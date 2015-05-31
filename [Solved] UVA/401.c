#include <stdio.h>
#include <string.h>

int palin(char a[100],int l)
{
    int i,j,k;
    k=l/2;
    for(i=0,j=l-1;i<k;i++,j--)
    {
        if(a[i]!=a[j])
        {
            return 0;
        }
    }
    return 1;
}

int mirror(char a[100],int l)
{
    int j,i;
    char b[100];
    for(i=0,j=l-1;i<l;i++,j--)
    {
        if(a[i]=='A')
        {
            b[j]='A';
        }
        else if(a[i]=='E')
        {
            b[j]='3';
        }
        else if(a[i]=='H')
        {
            b[j]='H';
        }
        else if(a[i]=='I')
        {
            b[j]='I';
        }
        else if(a[i]=='J')
        {
            b[j]='L';
        }
        else if(a[i]=='L')
        {
            b[j]='J';
        }
        else if(a[i]=='M')
        {
            b[j]='M';
        }
        else if(a[i]=='O')
        {
            b[j]='O';
        }
        else if(a[i]=='S')
        {
            b[j]='2';
        }
        else if(a[i]=='T')
        {
            b[j]='T';
        }
        else if(a[i]=='U')
        {
            b[j]='U';
        }
        else if(a[i]=='V')
        {
            b[j]='V';
        }
        else if(a[i]=='W')
        {
            b[j]='W';
        }
        else if(a[i]=='Y')
        {
            b[j]='Y';
        }
        else if(a[i]=='Z')
        {
            b[j]='5';
        }
        else if(a[i]=='1')
        {
            b[j]='1';
        }
        else if(a[i]=='2')
        {
            b[j]='S';
        }
        else if(a[i]=='3')
        {
            b[j]='E';
        }
        else if(a[i]=='5')
        {
            b[j]='Z';
        }
        else if(a[i]=='8')
        {
            b[j]='8';
        }
        else
        {
            return 0;
        }
    }
    b[l]='\0';
    if(strcmp(a,b)==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

main()
{
    int n,pal,mir,l,i;
    char a[100];
    i=0;
    while(gets(a))
    {
        l=strlen(a);
        pal=palin(a,l);
        mir=mirror(a,l);
        if(pal==1)
        {
            if(mir==1)
            {
                printf("%s -- is a mirrored palindrome.\n\n",a);
            }
            else
            {
                printf("%s -- is a regular palindrome.\n\n",a);
            }
        }
        else if(mir==1)
        {
            printf("%s -- is a mirrored string.\n\n",a);
        }
        else
        {
            printf("%s -- is not a palindrome.\n\n",a);
        }
    }
    return 0;
}

#include <stdio.h>
#include <string.h>

int add(char c[],char b[])
{
    char a[10000];
    int sum=0,carry=0,i,j,k,l,m;
    l=strlen(c);
    k=strlen(b);
        for(i=0,j=0,m=0;i<l && j<k;i++,j++)
        {
            sum=(c[i]-48)+(b[j]-48)+carry;
            a[m]=sum%10+48;
            carry=sum/10;
            m++;
        }
    if(i!=l)
    {
        while(i<l)
        {
        sum=(c[i]-48)+carry;
        a[m]=sum%10+48;
        carry=sum/10;
        m++;
        i++;
        }

    }
    else if(j!=k)
    {
        while(j<k)
        {
        sum=(b[j]-48)+carry;
        a[m]=sum%10+48;
        carry=sum/10;
        m++;
        j++;
        }
    }
    if(carry!=0)
    {
        a[m]=carry+48;
        m++;
    }
    a[m]='\0';
    strcpy(c,a);
}

main()
{
    char a[10000];
    char c[100000];
    int i,j,k,l,temp;
    c[0]='\0';
    while(gets(a))
    {
        l=strlen(a);
        if(strcmp(a,"0")==0)
        {
            break;
        }
        for(i=0,j=l-1;i<l/2;i++,j--)
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
        add(c,a);
    }
    l=strlen(c);
        for(i=0,j=l-1;i<l/2;i++,j--)
        {
            temp=c[i];
            c[i]=c[j];
            c[j]=temp;
        }
        printf("%s\n",c);

}

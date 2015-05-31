#include <stdio.h>
#include <string.h>

void add(char b[201],char b1[201],char b2[201])
{
    char c[201];
    int carry=0,i,k,j,m,n,l=0;
    m=strlen(b1);
    n=strlen(b2);
    for(i=0,k=0;i<m ||k<n  ;i++,k++)
    {
        if(i<m && k<n)
        {

            j=b1[i]-48+b2[k]-48+carry;
            carry=j/10;
            c[l]=j%10+48;
            l++;
        }
        else if(i<m)
        {
            j=b1[i]-48+carry;
            carry=j/10;
            c[l]=j%10+48;
            l++;
        }
        else
        {
            j=b2[k]-48+carry;
            carry=j/10;
            c[l]=j%10+48;
            l++;
        }
    }
    if(carry==1)
    {
        c[l]=49;
        l++;
    }
    k=0;
    for(i=0,j=0;i<l;i++)
    {
        if(c[i]=='0' && k==1)
        {
            b[j]=c[i];
            j++;
            k=1;
        }
        else if(c[i]!='0')
        {
            b[j]=c[i];
            j++;
            k=1;
        }
    }
    b[j]='\0';
}

main()
{
    int i;
    char a[201],b[201],c[201];
    scanf("%d",&i);
    getchar();
    while(i--)
    {
        scanf("%s %s",&a,&b);
        add(c,b,a);
        printf("%s\n",c);
    }
    return 0;
}

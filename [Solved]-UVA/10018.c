#include <stdio.h>
#include <string.h>


main()
{
    int m,test,i,sum,j,k,l,t;
    char a[100],b[100],c[100];
    scanf("%d",&test);
    getchar();
    for(t=0;t<test;t++)
    {
        k=0;
        gets(a);
        l=strlen(a);
        for(i=0,j=l-1;i<l;i++,j--)
        {
            b[i]=a[j];
        }
        b[i]='\0';
        while(strcmp(a,b))
        {
            sum=0;
            k++;
            for(i=0;i<l;i++)
            {
                sum=sum+(a[i]-48)+(b[i]-48);
                a[i]=(sum%10)+48;
                sum=sum/10;
            }
            if(sum>0)
            {
                a[i]=sum+48;
                i++;
                l++;
                a[i]='\0';
            }
            for(i=l-1,j=0;j<l;j++,i--)
            {
                b[j]=a[i];
            }
            b[j]='\0';
        }
        printf("%d %s\n",k,a);
    }
    return 0;

}

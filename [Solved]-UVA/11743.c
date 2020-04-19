#include <stdio.h>
#include <string.h>

main()
{
    int l,n,i,j,test1,k,sum,sum1,tot,m,test,e;
    char a[20],b[20];
    scanf("%d",&test);
    getchar();
    for(e=0;e<test;e++)
    {
        gets(a);
        l=strlen(a);
        for(i=0,j=0;i<l+1;i++)
        {
            if(a[i]!=' ')
            {
            b[j]=a[i];
            j++;
            }
        }
        k=strlen(b);
        sum=0;
        for(i=0;i<k;i=i+2)
        {
            n=b[i]-48;
            if(n*2>9)
            {
                m=(n*2)%9;
                if(m==0)
                {
                    m=9;
                }
                sum=sum+m;
            }
            else
            {
                m=n*2;
                sum=sum+m;
            }
        }
        sum1=0;
        for(i=1;i<k;i=i+2)
        {
            sum1=sum1+b[i]-48;
        }
        tot=sum+sum1;
        test1=tot%10;
        if(test1==0)
        {
            printf("Valid\n");
        }
        else
        {
            printf("Invalid\n");
        }
    }
    return 0;

}

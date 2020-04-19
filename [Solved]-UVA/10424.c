#include <stdio.h>
#include <string.h>

main()
{
    char a[26],b[26];
    int sum1,l,k,sum2,i;
    float per;
    while(gets(a))
    {
        gets(b);
        sum1=0;
        sum2=0;
        l=strlen(a);
        k=strlen(b);
        for(i=0;i<l;i++)
        {
            if(a[i]>='a' && a[i]<='z')
            {
                sum1+=a[i]-96;
            }
            else  if(a[i]>='A' && a[i]<='Z')
            {
                sum1+=a[i]-64;
            }
        }
        if(sum1%9==0)
        {
            sum1=9;
        }
        else if(sum1%9!=0)
        {
            sum1=sum1%9;
        }
        for(i=0;i<k;i++)
        {
            if(b[i]>='a' && b[i]<='z')
            {
                sum2+=b[i]-96;
            }
            if(b[i]>='A' && b[i]<='Z')
            {
                sum2+=b[i]-64;
            }
        }
        if(sum2%9==0)
        {
            sum2=9;
        }
        else if(sum2%9!=0)
        {
            sum2=sum2%9;
        }
        if(sum1>sum2)
        {
            per=((float) sum2/sum1)*100.00;
        }
        else
        {
            per=((float) sum1/sum2)*100.00;
        }
        printf("%0.2f %%\n",per);
    }
    return 0;

}

#include <stdio.h>
#include <math.h>
#include <string.h>
char a[1000000];
main()
{
    int i,j,l;
    long long sum;
    while(gets(a))
    {
        if(a[0]=='0'&&a[1]=='\0')
        {
            break;
        }
        l=strlen(a);
        sum=0;
        for(i=l,j=0;j<l;i--,j++)
        {
            sum=sum+((a[j]-48)*(pow(2,i)-1));
        }
        printf("%lld\n",sum);
    }
    return 0;
}

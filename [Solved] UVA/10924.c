#include <stdio.h>
#include <string.h>
#include <math.h>

main()
{
    char a[21];
    int i,j,n,sum;
    while(scanf("%s",&a)!=EOF)
    {
        sum=0;
        n=strlen(a);
        for(i=0;i<n;i++)
        {
            if(a[i]>='a' && a[i]<='z')
            {
                sum+=a[i]-96;
            }
            if(a[i]>='A' && a[i]<='Z')
            {
                sum+=a[i]-38;
            }
        }
        if(sum==1)
        {
            printf("It is a prime word.\n");

        }
        for(i=2;i<sum;i++)
        {
            if(sum % i == 0)
            {
                printf("It is not a prime word.\n");
                break;
            }
        }
        if(i==sum)
        {
            printf("It is a prime word.\n");
        }
    }
    return 0;
}

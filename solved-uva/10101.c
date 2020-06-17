#include <stdio.h>

main()
{
    long long n;
    int i,j=1,l,k;
    int a[10];
    while(scanf("%lld",&n)==1)
    {
        if(n==0)
        {
            printf("%4d. 0\n",j);
        }
        else
        {

        i=1;
        while(n>0)
        {
            if(i==2 || i==6)
            {
                a[i]=n%10;
                n=n/10;
            }
            else
            {
                a[i]=n%100;
                n=n/100;
            }
            i++;
        }
        i--;
        l=i;
        printf("%4d.",j);
        for(i=l;i>0;i--)
        {
            if(i==1 && a[i]!=0)
            {
                printf(" %d",a[i]);
                k++;
            }
            else if((i==2 && a[i]!=0) || (i==6 && a[i]!=0))
            {
                printf(" %d shata",a[i]);
            }
            else if((i==3 && a[i]!=0) || (i==7 && a[i]!=0))
            {
                printf(" %d hajar",a[i]);
            }
            else if((i==4 && a[i]!=0) || (i==8 && a[i]!=0))
            {
                printf(" %d lakh",a[i]);
            }
            else if(i==5  || (i==9 && a[i]!=0))
            {
                if(a[i]==0 && l>5)
                {
                    printf(" kuti");
                }
                else if(a[i]!=0)
                printf(" %d kuti",a[i]);
            }
        }
        printf("\n");
        }
        j++;
    }
    return 0;
}

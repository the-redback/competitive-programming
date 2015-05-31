#include <stdio.h>
#include <string.h>

main()
{
    char a[1001];
    int b[100];
    int i,j,k=0,l,sum,n;
    while(gets(a))
    {
        if(k!=0)
        {
            printf("\n");
        }
        l=strlen(a);
        for(i=0;i<100;i++)
        {
            b[i]=0;
        }
        for(i=0;i<l;i++)
        {
            j=a[i]-32;
            b[j]++;
        }
        for(i=0;i<l && i<100;i++)
        {
            sum=1111110;
            for(j=0;j<100;j++)
            {

                if(b[j]!=0 && sum>=b[j] )
                {
                    sum=b[j];
                    n=j;
                }
            }
            if(sum!=1111110)
            {
                printf("%d %d\n",n+32,sum);
                b[n]=0;
            }
        }
        k++;
    }
    return 0;
}

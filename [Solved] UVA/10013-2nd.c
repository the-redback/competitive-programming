#include <stdio.h>
int a[1000010],b[1000010],c[1000011];

main()
{

    int test,i,j,k,l,carry;
    long n;
    scanf("%d",&test);
    for(k=0;k<test;k++)
    {
        scanf("%ld",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&a[i],&b[i]);
        }
        carry=0;
        for(i=n-1;i>=0;i--)
        {
            l=a[i]+b[i]+carry;
            c[i+1]=l%10;
            carry=l/10;
        }
        c[0]=carry;
        if(k>0)
        {
            printf("\n");
        }
        if(c[0]>0)
        {
            printf("%d",c[0]);
        }
        for(i=1;i<=n;i++)
        {
            printf("%d",c[i]);
        }
        printf("\n");
    }
    return 0;
}

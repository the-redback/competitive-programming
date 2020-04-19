#include <stdio.h>

int sort(int a[100001],int n)
{
    int i,j,k;
    for(i=0;i<2;i++)
        {
            for(j=0;j<n-1-i;j++)
            {
                if(a[j]<a[j+1])
                {
                    k=a[j];
                    a[j]=a[j+1];
                    a[j+1]=k;
                }
            }
        }
}

main()
{
    int n,add,sum,i,j,k,a[100001];
    while(scanf("%d",&n))
    {
        if(n==0)
        {
            break;
        }
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }

        sum=0;
        while(n>1)
        {
            sort(a,n);
            a[n-2]=a[n-1]+a[n-2];
            sum=sum+a[n-2];
            n--;
        }
        printf("%d\n",sum);
    }
    return 0;
}

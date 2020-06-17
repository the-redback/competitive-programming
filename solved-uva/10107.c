#include <stdio.h>

int sort(int a[10001],int n)
{
    int i,j,k;
        for(j=n-1;j>0;j--)
        {
            if(a[j]<a[j-1])
            {
                k=a[j];
                a[j]=a[j-1];
                a[j-1]=k;
            }
        }
}

main()
{
    int i,k;
    int a[10001];
    i=0;
    while(scanf("%d",&a[i])!=EOF)
    {
        sort(a,i+1);
        if(i%2==0)
        {
            k=i/2;
            printf("%d\n",a[k]);
        }
        else if(i%2!=0)
        {
            k=i/2;
            k=(a[k]+a[k+1])/2;
            printf("%d\n",k);
        }
        i++;
    }
    return 0;
}

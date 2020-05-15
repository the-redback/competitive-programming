#include<stdio.h>
#include<math.h>

main()
{
    int v1[100],v2[100],v3[100];
    int a[101];
    int i,j=0,l=0,k=0,n,neg=0,pos=0,zero=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]<0)
        {
            v1[j++]=a[i];
            neg++;
        }
        else if(a[i]>0)
        {
            v2[k++]=a[i];
            pos++;
        }
        else
        {
            v3[l++]=a[i];
            zero++;
        }
    }
    if(pos>0)
    {
        if(neg%2==0)
        {
            neg--;
            v3[l++]=v1[--j];
            zero++;
        }
    }
    else if(pos==0)
    {
        v2[k++]=v1[--j];
        v2[k++]=v1[--j];
        neg=neg-2;
        pos+=2;
        if(neg%2==0)
        {
            neg--;
            v3[l++]=v1[--j];
            zero++;
        }
    }
        printf("%d",neg);
        for(i=0;i<neg;i++)
        {
            printf(" %d",v1[i]);
        }
        printf("\n%d",pos);
        for(i=0;i<pos;i++)
        {
            printf(" %d",v2[i]);
        }
        printf("\n%d",zero);
        for(i=0;i<zero;i++)
        {
            printf(" %d",v3[i]);
        }
        printf("\n");
    return 0;
}

#include<stdio.h>
#include<string.h>
#include <algorithm>
using namespace std;

main()
{
    int i,j,t,k,r,temp,c,n;
    char ch;
    int a[202];
    scanf("%d",&t);
    for(j=1;j<=t;j++)
    {
        scanf("%d %d",&n,&k);
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);


        for(i=0;i<k;i++)
        {
            scanf(" %c",&ch);
            if(ch=='S')
            {
                scanf("%d",&r);
                for(c=0;c<n;c++)
                    a[c]+=r;
            }
            else if(ch=='M')
            {
                scanf("%d",&r);
                for(c=0;c<n;c++)
                    a[c]*=r;
            }
            else if(ch=='D')
            {
                scanf("%d",&r);
                for(c=0;c<n;c++)
                    a[c]/=r;
            }
            else if(ch=='P')
            {
                scanf("%d %d",&r,&c);
                temp=a[r];
                a[r]=a[c];
                a[c]=temp;
            }
            else if(ch=='R')
            {
                for(c=0,r=n-1;c<n/2;c++,r--)
                {
                    temp=a[r];
                    a[r]=a[c];
                    a[c]=temp;
                }
            }
        }
        printf("Case %d:\n",j);
        for(i=0;i<n;i++)
        {
            if(i!=0)
                printf(" ");
            printf("%d",a[i]);
        }
        printf("\n");
    }
    return 0;
}

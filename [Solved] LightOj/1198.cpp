#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;
int main()
{
    int a[52];
    int b[52];
    int i,j,t,n,k,l,point;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        point=0;
        scanf("%d",&n);
        for(j=0;j<n;j++)
            scanf("%d",&a[j]);
        for(j=0;j<n;j++)
            scanf("%d",&b[j]);
        sort(a,a+n);
        sort(b,b+n);
        for(j=0;j<n;j++)
       {
           if(a[j]==-1)
                continue;
           for(k=n-1;k>=0;k--)
            {
                if(b[k]==-1)
                    continue;
                else if(a[j]<b[k] )
                {
                    continue;
                }
                else if(a[j]>b[k])
                {
                    point+=2;
                    a[j]=-1;
                    b[k]=-1;
                    continue;
                }
            }
       }
        for(j=0,k=0;j<n && k<n;)
        {
            if(a[j]==-1)
                j++;
            else if(b[k]==-1)
                k++;
            else if(a[j]==b[k])
            {
                point++;
                k++;
                j++;
            }
            else if(a[j]<b[k] )
            {
                j++;
            }
            else if(a[j]>b[k])
            {
                k++;
            }
        }
        printf("Case %d: %d\n",i+1,point);
    }
    return 0;
}

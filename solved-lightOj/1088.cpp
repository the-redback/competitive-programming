#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;

long arr[100010];

int bsearch(int v,int l, int h)
{
    int mid;
    while(h>=l)
    {
        mid=ceil((h+l)/2.0);
        if(arr[mid]==v)
            return mid;
        else if(arr[mid]<v)
            l=mid+1;
        else
            h=mid-1;
    }
    return h;
}

main()
{
    int i,j,t,T,n,q,x,y,sum;
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        scanf("%d %d",&n,&q);
        for(i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
        }
        printf("Case %d:\n",t);
        while(q--)
        {
            scanf("%d %d",&x,&y);
            i=bsearch(x,0,n-1);
            if(i<0)
                i=0;
            else if(arr[i]<x)
                i++;
            j=bsearch(y,0,n-1);
            sum=j-i+1;
            if(sum>0)
                printf("%d\n",sum);
            else
                printf("0\n");
        }
    }
    return 0;
}

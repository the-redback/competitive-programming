#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;

    int arr[2005];

int khujo(int v,int l, int h)
{
    int mid;
    while(l<=h)
    {
        mid=(l+h)/2;
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
    int sum,t,T,i,j,n;
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        scanf("%d",&n);
        for(i=0;i<n; i++)
        {
            scanf("%d",&arr[i]);
        }
        sort(arr,arr+n);
        sum=0;
        for(i=0;i<n-2;i++)
        {
            for(j=i+1;j<n-1;j++)
            {
                int k=khujo(arr[i]+arr[j],j+1,n-1);
                if(arr[k]==arr[i]+arr[j])
                    k--;
                sum+=k-j;
            }
        }
        printf("Case %d: %d\n",t,sum);
    }
    return 0;
}

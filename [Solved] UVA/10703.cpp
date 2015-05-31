#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
void swap(int *p,int *q)
{
    int *t;
    *t=*p;
    *p=*q;
    *q=*p;
}
main()
{
    bool a[510][510];
    int i,j,x1,y1,sum,k,h,l,x,n,y;
    while(scanf("%d %d %d",&k,&h,&n))
    {
        if(k==0 && h==0 && n==0)
            return 0;
        memset(a,1,sizeof(a));
        while(n--)
        {
            scanf("%d%d%d%d",&x,&y,&x1,&y1);
            if(x1<x)
                swap(x,x1);
            if(y1<y)
                swap(y,y1);
            for(i=x;i<=x1;i++)
                for(j=y;j<=y1;j++)
                    a[i][j]=0;
        }
        sum=0;
        for(i=1;i<=k;i++)
            for(j=1;j<=h;j++)
            {
              if(a[i][j])
                    sum++;
            }
        if(sum==0)
            puts("There is no empty spots.");
        else if(sum==1)
            puts("There is one empty spot.");
        else
            printf("There are %d empty spots.\n",sum);
    }
    return 0;
}

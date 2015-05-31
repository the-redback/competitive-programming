#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
using namespace std;

main()
{
    int t,i,sum,j,k,l,n,m,min,max;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d %d",&n,&m);
        if(n>m)
        {
            min=m;
            max=n;
        }
        else
        {
            max=m;
            min=n;
        }
        if(min==1)
        {
            sum=max;
        }
        else if(min==2)
        {
            if(max%2!=0)
                sum=max+1;
            else
            {
                j=max/2;
                if(j%2==0)
                    sum=max;
                else
                    sum=(j+1)*2;
            }
        }
        else
            sum=ceil((n*m)/2.0);

        printf("Case %d: %d\n",i,sum);
    }
    return 0;
}

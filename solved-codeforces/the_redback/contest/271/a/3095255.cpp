#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
using namespace std;

main()
{
    int a[4];
    int n,i,j,k,l,m;
    scanf("%d",&n);
    while(1)
    {
        n++;
        i=n;
        a[0]=i%10;
        i=i/10;
        a[1]=i%10;
        i=i/10;
        a[2]=i%10;
        i=i/10;
        a[3]=i%10;
        i=i/10;
        sort(a,a+4);
        for(i=0;i<3;i++)
        {
            if(a[i]==a[i+1])
                break;
        }
        if(i==3)
        {
            printf("%d\n",n);
            return 0;
        }
    }

    printf("%d\n",k);
    return 0;
}

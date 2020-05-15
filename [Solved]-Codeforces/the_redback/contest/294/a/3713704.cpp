#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
main()
{
    int a[101];
    int n,i,j,k,l;
    a[0]=0;
    while(~scanf("%d",&n))
    {
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        scanf("%d",&k);
        int x,y;
        while(k--)
        {
            scanf("%d%d",&x,&y);
            if(x-1!=0)
            {
                a[x-1]+=y-1;
            }

            if(x+1<=n)
            {
                a[x+1]+=a[x]-y;;
            }
            a[x]=0;
        }
        for(i=1;i<=n;i++)
        {
            printf("%d\n",a[i]);
        }
    }
    return 0;
}

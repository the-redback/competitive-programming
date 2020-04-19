#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;
#define mem(x,y) memset(x,y,sizeof(x));
main()
{
    int a[15],i,j,k,m,n,t;
    scanf("%d",&t);
    puts("Lumberjacks:");
    while(t--)
    {
        for(i=0;i<10;i++)
            scanf("%d",&a[i]);
        if(a[0]>a[9])
        {
            reverse(a,a+10);
        }
        for(i=0;i<9;i++)
        {
            if(a[i]>a[i+1])
            {
                puts("Unordered");
                break;
            }
        }
        if(i==9)
            puts("Ordered");
    }
    return 0;
}

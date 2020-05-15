#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;

main()
{
    int t,n;
    int m,side;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        side=360/(180-n);
        m=((side-2)*180)/side;
        if(m==n)
            printf("YES\n");

        else
            printf("NO\n");
    }
    return 0;
}

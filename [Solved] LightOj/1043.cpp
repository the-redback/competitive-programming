#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;

main()
{
    double sum,ab,ac,bc,r;
    int t,T;
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        scanf("%lf %lf %lf %lf",&ab,&ac,&bc,&r);
        sum=r/(r+1);
        sum=sqrt(sum);
        sum*=ab;
        printf("Case %d: %lf\n",t,sum);
    }
    return 0;
}

#include <stdio.h>
#include <math.h>
int main()
{
    int t,i;
    double t1,t2,u,v,d,j;
    scanf("%d",&t);
    for(i=0; i<t; i++)
    {
        scanf("%lf%lf%lf",&d,&v,&u);
        if(u>v && v!=0)
        {
            t1=d/u;
            t2=d/(sqrt(u*u-v*v));
            printf("Case %d: %.3f\n",i+1,t2-t1);
        }
        else printf("Case %d: can't determine\n",i+1);
    }
    return 0;
}

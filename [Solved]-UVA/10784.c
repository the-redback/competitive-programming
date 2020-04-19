#include <stdio.h>
#include <math.h>

main()
{
    long long l;
    int i=0;
    while(scanf("%lld",&l)!=EOF)
    {
        i++;
        if(l == 0)
        {
            break;
        }
        l=ceil((3+sqrt(9+4*2*l))/2);

        printf("Case %d: %lld\n",i,l);
    }
    return 0;
}

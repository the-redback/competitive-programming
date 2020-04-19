#include <stdio.h>

main()
{
    int min,avg,max,i,n;

    scanf("%d",&n);

    for(i=0;i<n;i++)

    {
        scanf("%d%d%d",&min,&avg,&max);
        if(min>avg && min<max || min<avg && min>max)
        {
            printf("Case %d: %d\n",i+1,min);
        }
        else if(avg>min && avg<max || avg<min && avg>max)
        {

            printf("Case %d: %d\n",i+1,avg);

        }
        else if(max>avg && max<min || max <avg && max>min)
        {
            printf("Case %d: %d\n",i+1,max);
        }
    }
    return 0;
}

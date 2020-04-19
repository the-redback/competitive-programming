#include <stdio.h>

main ()
{
    int a,b,c,n,i,d,e,f,g,h,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d/%d/%d",&a,&b,&c);
        scanf("%d/%d/%d",&d,&e,&f);
        h=((f*365)+(e*30)+d);
        g=((c*365)+(b*30)+a);

        if(h>g)
        {
            printf("Case #%d: Invalid birth date\n",i+1);
        }
        else
        {
            j=(g-h)/365;
            if(j>130)
            {
                printf("Case #%d: Check birth date\n",i+1);
            }
            else
            {
                printf("Case #%d: %d\n",i+1,j);
            }

            }
    }
    return 0;

}

#include <stdio.h>

main()
{
    int N,B,k,H,W,i,j,l,hotel,week,h[20],w,s[20];
    while(scanf("%d%d%d%d",&N,&B,&H,&W)==4)
    {
        hotel=0;
        for(i=0;i<20;i++)
        {
            s[i]=0;
        }
        for(i=0;i<H;i++)
        {
            scanf("%d",&h[i]);
            k=h[i]*N;
            if(k<=B)
            {
                for(j=0;j<W;j++)
                {
                    scanf("%d",&w);
                    if(w>=N)
                    {
                        s[i]=k;
                    }
                }
            }
            else
            for(j=0;j<W;j++)
                {
                    scanf("%d",&w);
                }

        }
        for(i=0;i<20;i++)
        {
            if(s[i]!=0)
            {
                if(hotel==0 || s[i]<hotel)
                {
                    hotel=s[i];
                }
            }
        }
        if(hotel!=0)
        {
            printf("%d\n",hotel);
        }
        else
        {
            printf("stay home\n");
        }
    }
    return 0;
}

#include <stdio.h>

main()
{
    int i,n,term1,term2,final,att,ct1,ct2,ct3,ct,total;

    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d%d%d%d%d%d%d",&term1,&term2,&final,&att,&ct1,&ct2,&ct3);

        if(ct1>=ct3 && ct2>=ct3)
        {
            ct=(ct1+ct2)/2;
        }
        else if(ct1>=ct2 && ct3>=ct2)
        {
            ct=(ct1+ct3)/2;
        }
        else if(ct2>=ct1 && ct3>=ct1)
        {
            ct=(ct2+ct3)/2;
        }
        total=term1+term2+final+att+ct;

        if(total>=90)
        {
            printf("Case %d: A",i+1);
        }
        else if(total<90 && total>=80)
        {
            printf("Case %d: B",i+1);
        }
        else if(total<80 && total>=70)
        {
            printf("Case %d: C",i+1);
        }
        else if(total<70 && total>=60)
        {
            printf("Case %d: D",i+1);
        }
        else if(total<60)
        {
            printf("Case %d: F",i+1);
        }
        printf("\n");
    }
    return 0;
}

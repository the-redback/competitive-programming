#include <stdio.h>
#include <string.h>

main()
{
    char a[200];
    int i,j,count,m,k,test,n,l;
    scanf("%d",&test);
    getchar();
    for(k=0;k<test;k++)
    {
        count=0;
        m=0;
        gets(a);
        l=strlen(a);
        for(i=0;i<l;i++)
        {
            if(a[i]=='M')
            {
                count+=1;
                m++;
            }
            else if(a[i]=='F')
            {
                count-=1;
                m++;
            }
        }
        if(count==0 && m>2)
        {
            printf("LOOP\n");
        }
        else
        {
            printf("NO LOOP\n");
        }

    }
    return 0;
}

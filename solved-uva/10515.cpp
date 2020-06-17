#include <stdio.h>
#include <string.h>

main()
{
    char a[101], b[101];
    int l2,j,l1,n,m;
    while(scanf("%s %s",a,b)==2)
    {
        l1=strlen(a);
        l2=strlen(b);
        m=a[l1-1]-48;
        n=0;
        if(strcmp(a,"0")==0 && strcmp(b,"0")==0)
        {
            return 0;
        }
        else if(strcmp(b,"0")==0)
        {
            printf("1\n");
        }
        else
        {
            if(m==0)
            {
                printf("0\n");
            }
            else
            {
                if(l2>=2)
                n=(10*(b[l2-2]-48))+(b[l2-1]-48);
                else
                n=b[l2-1]-48;
                if(n==0)
                {
                    n=4;
                }
                for(j=m;n>1;n--)
                {
                    j=(j*m);
                    j=j%10;
                }
                printf("%d\n",j);
            }
        }
    }
    return 0;
}

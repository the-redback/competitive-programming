 #include <stdio.h>
#include <cstring>


main()
{
    char a[101][55];
    char b[10];
    int i,j,k,l,t,n;
    strcpy(a[0],"http://www.lightoj.com/");
    scanf("%d",&t);
    getchar();
    for(l=1;l<=t;l++)
    {
        printf("Case %d:\n",l);
        n=0;
        i=0;
        while(scanf("%s",b))
        {
            if(strcmp(b,"VISIT")==0)
            {
                i++;
                n=i;
                scanf("%s",a[i]);
                printf("%s\n",a[i]);
            }
            else if(strcmp(b,"BACK")==0)
            {
                if(i-1>=0)
                {
                    i--;
                    printf("%s\n",a[i]);
                }
                else
                    printf("Ignored\n");
            }
            else if(strcmp(b,"FORWARD")==0)
            {
                if(i+1<=n)
                {
                    i++;
                    printf("%s\n",a[i]);
                }
                else
                    printf("Ignored\n");
            }
            else if(strcmp(b,"QUIT")==0)
                break;
        }

    }
    return 0;
}

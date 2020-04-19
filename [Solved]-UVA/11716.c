#include <stdio.h>
#include <string.h>
#include <math.h>

main()
{
    char  a[10001],b[100][100];
    int test,l,k,i,j,n,m;
    scanf("%d",&test);
    getchar();
    for(k=0;k<test;k++)
    {
        gets(a);
        l=strlen(a);
        n=sqrt(l);
        m=0;
        if(n*n == l)
        {
            for(i=0;i<n;i++)
            {
                for(j=0;j<n;j++)
                {
                    b[i][j]=a[m];
                    m++;
                }
            }
            for(i=0;i<n;i++)
            {
                for(j=0;j<n;j++)
                {
                    printf("%c",b[j][i]);
                }
            }
            printf("\n");
        }
        else
        {
            printf("INVALID\n");
        }


    }
    return 0;
}

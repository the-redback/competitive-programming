#include <stdio.h>
#include <string.h>

const int max=10000;
char x[max],y[max];
int c[max][max];
int lcs(int n, int m)
{
    int i,j,l;

    for(i=1;i<=n;i++)
        c[i][0]=0;

    for(j=0;j<=m;j++)
        c[0][j]=0;

    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {
            if(x[i-1]==y[j-1])
                c[i][j]=c[i-1][j-1]+1;

            else if(c[i-1][j]>=c[i][j-1])
                c[i][j]=c[i-1][j];

            else
                c[i][j]=c[i][j-1];
        }

        return c[n][m];
}

main()
{
    int n,m,i;
    while(gets(x))
    {
        gets(y);
        n=strlen(x);
        m=strlen(y);

        i=lcs(n,m);
        printf("%d\n",i);
    }
    return 0;
}


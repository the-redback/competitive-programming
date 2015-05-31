#include <stdio.h>
const int max=25;
int x[max],y[max];
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
    int n,m,i,j,k,t;
    scanf("%d",&n);

    for(i=1;i<=n;i++)
    {
        scanf("%d",&m);
        x[m-1]=i;
    }

    while(scanf("%d",&m)==1)
    {
        y[m-1]=1;
        for(i=2;i<=n;i++)
        {
            scanf("%d",&m);
            y[m-1]=i;
        }

        i=lcs(n,n);
        printf("%d\n",i);
    }
    return 0;
}


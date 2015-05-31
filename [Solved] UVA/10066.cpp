#include <stdio.h>
const int max=101;
int x[max],y[max];

int lcs(int n, int m)
{
    int c[max][max];
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
    int n,m,i,j,k=0;
    while(scanf("%d %d",&n,&m))
    {
        k++;
        if(n==0 && m==0)
        {
            return 0;
        }
        for(i=0;i<n;i++)
        scanf("%d",&x[i]);

        for(i=0;i<m;i++)
        scanf("%d",&y[i]);

        i=lcs(n,m);
        printf("Twin Towers #%d\nNumber of Tiles : %d\n\n",k,i);
    }
    return 0;
}

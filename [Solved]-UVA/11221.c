#include <stdio.h>
#include <string.h>
#include <math.h>
main()
{
    char a[10005],b[10005],c[1000][1000];
    int t,r,h,i,j,k,l,m,n,tc;
    scanf("%d",&tc);
    getchar();
    for(t=0;t<tc;t++)
    {
        gets(a);
        l=strlen(a);
        j=0;

        for(i=0;i<l;i++)
        {
            if(a[i]>='a' && a[i]<='z')
            {
                b[j]=a[i];
                j++;
            }
        }
        b[j]='\0';
        l=j;
        r=sqrt(l);
        if(r*r==l)
        {
            k=0;
            for(i=0;i<r;i++)
            {
                for(j=0;j<r;j++)
                {
                    c[j][i]=b[k];
                    k++;
                }
            }
            for(i=0,m=r-1;i<r;i++,m--)
            {
                for(j=0,n=r-1;j<r;j++,n--)
                {
                    if(c[i][j]!=c[j][i]|| c[i][j]!=c[n][m] || c[n][m]!=c[m][n])
                    {
                        break;
                    }
                }
                if(j!=r)
                {
                    break;
                }
            }
            if(i==r && j==r)
            {
                printf("Case #%d:\n",t+1);
                printf("%d\n",r);
            }
            else
            {
                printf("Case #%d:\n",t+1);
                printf("No magic :(\n");
            }

        }
        else
        {
            printf("Case #%d:\n",t+1);
            printf("No magic :(\n");
        }
    }
    return 0;
}

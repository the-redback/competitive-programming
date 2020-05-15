#include<stdio.h>
#include<string.h>
#include <algorithm>
using namespace std;
int a[200][200];

main()
{
    int i,j,k,l,t;
    int n;
    while(~scanf("%d%d",&k,&n))
    {
        memset(a,0,sizeof(a));
        for(i=0;i<k;i++)
            a[i][i]=n;
        for(i=0;i<k;i++)
        {
            for(j=0;j<k;j++)
                {
                    if(j!=0)
                        printf(" ");
                    printf("%d",a[i][j]);
                }
                printf("\n");
        }
    }
    return 0;
}

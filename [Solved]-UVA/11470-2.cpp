#include <stdio.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <ctype.h>
#include <string>
using namespace std;
#define mem(x,y) memset(x,y,sizeof(x));

main()
{
    int a[20][20];
    bool b[20][20];
    int i,j,k,l,m,sum,t=1,n,flag;
    while(scanf("%d",&n)==1)
    {
        mem(b,1);
        if(n==0)
            return 0;
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                scanf("%d",&a[i][j]);
        printf("Case %d:",t++);
        for(k=0,l=n-1;k<=l;k++,l--)
        {
            sum=0;
            for(i=0;i<n;i++)
            {
                for(j=0;j<n;j++)
                {
                    if(i==k||i==l||j==k||j==l)
                        if(b[i][j])
                        {
                            sum+=a[i][j];
                            b[i][j]=0;
                        }
                }
            }
            printf(" %d",sum);
        }
        puts("");
    }
}

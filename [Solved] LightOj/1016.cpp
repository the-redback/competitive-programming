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
    int t,T,i,j,k,l,sum,m,n,N,M;
    int a[50010];
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        scanf("%d %d",&N,&M);
        for(i=0;i<N;i++)
            scanf("%d %d",&n,&a[i]);
        sort(a,a+N);
        sum=1;
        k=a[0];
        for(i=1;i<N;i++)
        {
            if(a[i]-k>M)
            {
                sum++;
                k=a[i];
            }
        }
        printf("Case %d: %d\n",t,sum);
    }
    return 0;
}

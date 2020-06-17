#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int a[20],N,cont,M;
void call(int taken,int last)
{
    if(taken==N)
    {
        cont++;
        return;
    }
    for(int i=0;i<M;i++)
    {
        if(taken==0||abs(a[i]-last)<=2)
        {
            call(taken+1,a[i]);
        }
    }
    return;
}

main()
{
    int tc;
    scanf("%d",&tc);
    for(int t=1;t<=tc;t++)
    {
        int n,m;
        scanf("%d%d",&M,&N);
        for(int i=0;i<M;i++)
            scanf("%d",&a[i]);
        cont=0;
        call(0,0);
        printf("Case %d: %d\n",t,cont);
    }
    return 0;
}

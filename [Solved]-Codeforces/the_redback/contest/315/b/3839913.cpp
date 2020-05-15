#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
__int64 a[100002],b[100002];
main()
{
    bool c[100002];
    memset(c,0,sizeof(c));
    __int64 xtra,l;
    int i,j,k,m,n;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
    {
        scanf("%I64d",&a[i]);
    }
    xtra=0;
    while(m--)
    {
        scanf("%d ",&k);
        if(k==1)
        {
            scanf("%d %I64d",&j,&l);
            a[j]=l;
            b[j]=xtra;
            c[j]=1;
        }
        else if(k==2)
        {
            scanf("%I64d",&l);
            xtra+=l;
        }
        else if(k==3)
        {
            scanf("%d",&j);
            if(c[j]==1)
                printf("%I64d\n",a[j]+xtra-b[j]);
            else
                printf("%I64d\n",a[j]+xtra);
        }
    }
    return 0;
}

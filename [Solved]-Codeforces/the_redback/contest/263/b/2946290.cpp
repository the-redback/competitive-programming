#include <stdio.h>
#include <algorithm>
using namespace std;

main()
{
    int a[51];
    int i,j,l,n,k;
    scanf("%d %d",&n,&k);
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);

    if(n<k)
    {
        printf("-1\n");
        return 0;
    }

    sort(a,a+n);

    k=n-k;
    printf("%d 0\n",a[k]);

    return 0;
}

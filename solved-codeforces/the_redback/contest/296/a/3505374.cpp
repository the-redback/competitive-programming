#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

main()
{

    int a[101];
    int b[1001];
    memset(b,0,sizeof(b));
    int i,j,k,l=0,n;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        j=a[i];
        b[j]++;
        if(j>l)
            l=j;
    }
    k=ceil(n/2.0);
    for(i=0;i<=l;i++)
    {
        if(b[i]>k)
        {

            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    return 0;
}

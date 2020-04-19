#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
double a[1000002];
main()
{
    int i,j,t,k,n,m;
    for(i=1;i<=1000000;i++)
        a[i]=log(i)+a[i-1];

    scanf("%d",&t);
    for(j=1;j<=t;j++)
    {
        scanf("%d %d",&n,&k);
        m=a[n]/log(k)+1;
        printf("Case %d: %d\n",j,m);
    }
    return 0;
}

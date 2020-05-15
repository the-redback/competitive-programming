#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
main()
{
    int n,m,i,j,k,l;
    while(~scanf("%d",&n))
    {
        i=n;
        j=n/10;
        k=(n/100)*10+(n%10);
        m=max(i,j);
        m=max(m,k);
        printf("%d\n",m);
    }
    return 0;
}

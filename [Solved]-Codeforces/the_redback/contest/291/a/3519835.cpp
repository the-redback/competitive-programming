#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
main()
{
    long a[1001];
    long i,j,k=0,l,n;
    scanf("%ld",&n);
    for(i=0;i<n;i++)
    {
        scanf("%ld",&a[i]);
    }
    sort(a,a+n);
    if(a[0]==a[1] && a[0]!=0)
        k++;
    for(i=2;i<n;i++)
    {
        if( a[i]== a[i-1] && a[i-1]==a[i-2] && a[i]!=0)
        {
            printf("-1\n");
            return 0;
        }
        else if(a[i]==a[i-1] &&a[i]!=0)
        {
            k++;
        }
    }
    printf("%ld\n",k);
    return 0;
}

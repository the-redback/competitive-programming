#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

main()
{
    int n;
    int a[100100];
    scanf("%d",&n);
    int i,j,k=0,tc=0,l,m;
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]==i)
            k++;
    }
    for(i=0;i<n;i++)
    {
        if(i!=a[i])
        {
            l=a[i];
            if(a[l]==i && tc==0)
            {
                k+=2;
                tc=1;
                break;
            }
        }
    }
    if(tc==0 && k!=n)
        k++;
    printf("%d\n",k);
    return 0;
}

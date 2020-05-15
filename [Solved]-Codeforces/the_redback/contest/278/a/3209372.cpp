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
    int a[150];
    int i,j,min,max,s,t,n;
    int sum1,sum2;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    scanf("%d %d",&s,&t);
    if(s<t)
        {
            min=s;
            max=t;
        }
    else
    {
        min=t;
        max=s;
    }
    sum1=0;
    for(i=min-1;i<max-1;i++)
        sum1+=a[i];
    sum2=0;
    for(i=0;i<min-1;i++)
        sum2+=a[i];
    for(i=max-1;i<n;i++)
        sum2+=a[i];

    if(sum1<sum2)
        printf("%d\n",sum1);
    else
        printf("%d\n",sum2);
    return 0;
}

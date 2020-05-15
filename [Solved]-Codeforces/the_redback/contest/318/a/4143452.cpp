#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;
#define mem(x,y) memset(x,y,sizeof(x));

main()
{
    __int64 k,l,m,n,t;

    scanf("%I64d %I64d",&n,&k);
    m=ceil(n/2.0);
    if(k<=m)
    {
        k=k*2-1;
    }
    else
    {
        k=k-m;
        k=k*2;
    }
    printf("%I64d\n",k);
    return 0;
}
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;
main()
{
    __int64 a,b,x,sum,m,n;
    scanf("%I64d %I64d %I64d",&a,&b,&x);
    sum=0;
    if(a>b)
        swap(a,b);
    if(b>=x)
        sum=0;
    else if(a<=0 && b<=0 )
        sum=-1;
    else
    {
        if(a<0)
        {
            m=abs(a/b);
            a=b-(abs(a)%b);
            sum=m+1;
        }
        while(b<x)
        {
            m=a+b;
            a=b;
            b=m;
            sum++;
        }
    }
    printf("%I64d\n",sum);
        return 0;
}

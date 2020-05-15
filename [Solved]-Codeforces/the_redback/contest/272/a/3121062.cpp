#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;


main()
{
    int i,j,k,l,t,n,sum=0;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%d",&k);
        sum+=k;
    }
    t++;
    i=sum/t;
    i++;
    i=i*t;
    if(t==2)
    {
        if(sum%2==0)
            n=2;
        else
            n=3;
    }
    else if(t==3)
    {
        if(sum%t==1)
        n=4;
        else
        n=3;
    }
    else if(t<5)
        n=t;
    else if(i-sum<5||sum%t==0)
        n=4;
    else
        n=5;
    printf("%d\n",n);
}

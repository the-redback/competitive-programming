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
    int sum,j,k,l,n,m,mi,ma;
    while(scanf("%d %d",&n,&m))
    {
        if(n==0 && m==0)
            return 0;
        mi=min(n,m);
        ma=max(n,m);
        if(mi==1)
        {
            sum=ma;
        }
        else if(mi==2)
        {
            if(ma%2!=0)
                sum=ma+1;
            else
            {
                j=ma/2;
                if(j%2==0)
                    sum=ma;
                else
                    sum=(j+1)*2;
            }
        }
        else
            sum=ceil((n*m)/2.0);

        printf("%d knights may be placed on a %d row %d column board.\n",sum,n,m);
    }
    return 0;
}

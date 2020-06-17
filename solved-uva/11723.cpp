#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;
main()
{
    int n,t=1,r,s,i,j,k;
    while(scanf("%d%d",&r,&n)==2)
    {
        if(r==0 && n==0)
            return 0;
        k=(r-1)/n;
        if(k<=26)
            printf("Case %d: %d\n",t++,k);
        else
            printf("Case %d: impossible\n",t++);
    }
    return 0;
}

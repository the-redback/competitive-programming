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
    int sum,x,y,n,t=1,i,tc;
    long long m,j,k,l;
    while(~scanf("%d%d%d",&n,&x,&y))
    {
        for(i=1;i<=n;i++)
        {
            m=pow(2,i);
            k=ceil(x/(double)m);
            l=ceil(y/(double)m);
            if(k==l || i==n)
                break;
        }
        printf("%d\n",i);
    }
    return 0;
}

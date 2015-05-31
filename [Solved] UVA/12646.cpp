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
    int i,j,k,l,n,m;
    int t,tc;
    while(~scanf("%d%d%d",&n,&m,&k))
    {
        if(n!=m && n!=k && m==k)
            puts("A");
        else if(m!=n && m!=k&& n==k)
            puts("B");
        else if(k!=m && k!=n && m==n)
            puts("C");
        else
            puts("*");
    }
    return 0;
}

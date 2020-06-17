#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
#include<stack>
using namespace std;
main()
{
    int i,j,l;
    int n,k;
    while(scanf("%d %d",&n,&k)==2)
    {
        if(n==k)
        {
            printf("-1\n");
            continue;
        }
        j=n-k;
        printf("%d",n-k);
        for(i=2;i<=j;i++)
        {
            printf(" %d",i-1);
        }
        for(i=j+1;i<=n;i++)
        {
            printf(" %d",i);
        }
        puts("");
    }
    return 0;
}

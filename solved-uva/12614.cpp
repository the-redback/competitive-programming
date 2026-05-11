/**
 *                                   ____
 *       ____ ___  ____ ________  __/ __/
 *      / __ `__ \/ __ `/ ___/ / / / /_
 *     / / / / / / /_/ / /  / /_/ / __/
 *    /_/ /_/ /_/\__,_/_/   \__,_/_/
 *
 *    @link : https://the-redback.com
 */
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
    int sum,x,y,n,t=1,tc,i,j,k,l,m;
    long long a[200];
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%lld",&a[i]);
        sort(a,a+n);
        printf("Case %d: %lld\n",t++,a[n-1]);
    }
    return 0;
}

/**
 *    @author     : Maruf Tuhin
 *    @School     : CUET CSE 11
 *    @TOPCODER   : the_redback
 *    @CodeForces : the_redback
 *    @UVA        : the_redback
 *    @link       : http://www.fb.com/maruf.2hin
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

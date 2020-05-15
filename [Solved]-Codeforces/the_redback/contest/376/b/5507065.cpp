/**
 *    @author     : Maruf Tuhin
 *    @School     : CUET CSE 11
 *    @TOPCODER   : the_redback
 *    @CodeForces : maruf.2hin
 *    @UVA        : Redback
 *    @link       : http://www.fb.com/maruf.2hin
 *
 */
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
using namespace std;

#define inf HUGE_VAL


main()
{
    int a[1010];
    int n,m;
    int i,j,l,x,k,y,z;
    long long sum;
    while(~scanf("%d%d",&n,&m))
    {
        memset(a,0,sizeof(a));
        while(m--)
        {
            scanf("%d%d%d",&x,&y,&z);
            a[x]+=z;
            a[y]-=z;
        }
        sum=0;
        for(i=0;i<=n;i++)
            if(a[i]>0)
                sum+=a[i];
        cout<<sum<<endl;
    }
    return 0;
}

















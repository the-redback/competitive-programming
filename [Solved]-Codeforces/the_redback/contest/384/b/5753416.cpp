/**
 *    @author     : Maruf Tuhin
 *    @School     : CUET CSE 11
 *    @Topcoder   : the_redback
 *    @CodeForces : the_redback
 *    @UVA        : Redback
 *    @link       : http://www.fb.com/maruf.2hin
 */
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<set>
#include<sstream>
#include<stack>
using namespace std;

#define inf 10000000
#define mem(a,b) memset(a,b,sizeof(a))
#define NN 200000
//char a[1010][1010];
main()
{
    int tc,t=1;
    int n,m,i,j,k,l,u,v;
    while(~scanf("%d%d%d",&n,&m,&k))
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
                scanf("%d",&l);
        }
        l=(m*(m-1))/2;
        printf("%d\n",l);
        if(k==0)
        {
            for(i=0;i<m-1;i++)
                for(j=0;j<m-i-1;j++)
                    printf("%d %d\n",j+1,j+2);
        }
        else
        {
            for(i=0;i<m-1;i++)
                for(j=0;j<m-i-1;j++)
                    printf("%d %d\n",j+2,j+1);
        }

    }
    return 0;
}

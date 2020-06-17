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
char a[1010][1010];
main()
{
    int tc,t=1;
    int n,m,i,j,k,l,u,v;
    while(~scanf("%d",&n))
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
                a[i][j]='.';
            a[i][j]=0;
        }
        k=0;
        l=0;
        for(i=0;i<n;i++)
        {
            for(j=k%2;j<n;j+=2)
                a[i][j]='C',l++;
            k++;
        }
        printf("%d\n",l);
        for(i=0;i<n;i++)
            puts(a[i]);
    }
    return 0;
}

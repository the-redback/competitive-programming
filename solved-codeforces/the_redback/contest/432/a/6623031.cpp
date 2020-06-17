/**
 *    @author     : Maruf Tuhin
 *    @School     : CUET CSE 11
 *    @Topcoder   : the_redback
 *    @CodeForces : the_redback
 *    @UVA        : the_redback
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

#define ppb pop_back
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 1e9
#define eps 1e-9
#define NN 400010


main()
{
    ios_base::sync_with_stdio(false);
    int t,tc;
    //cin>>tc;
    int i,j,k,l,m,n;
    while(cin>>n>>k)
    {
        int total=0;
        for(i=0;i<n;i++)
        {
            cin>>j;
            if(j+k<=5)
                total++;
        }
        printf("%d\n",(int)total/3);
    }
    return 0;
}

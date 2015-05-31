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

#define mp make_pair
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 1e9
#define eps 1e-9
#define NN 1050


main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t=1,tc;
    cin>>tc;
    int i,j,k,l;
    int r,c;
    while(tc--)
    {
        cin>>r>>c;
        int sum=0;
        for(i=1;i<=r;i++)
        {
            for(j=1;j<=c;j++)
            {
                cin>>k;
                if((r-i+c-j)%2)
                    sum^=k;
            }
        }
        if(sum)
            printf("Case %d: win\n",t++);
        else
            printf("Case %d: lose\n",t++);

    }
    return 0;
}

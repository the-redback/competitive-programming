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
#define NN 111


main()
{
    ios_base::sync_with_stdio(false);
    int t=1,tc;
    int k,l,n,m,i,r;
    cin>>tc;
    while(tc--)
    {
        cin>>n>>m;
        int res=0;
        while(n--)
        {
            k=0;
            for(i=0;i<m;i++)
            {
                cin>>l;
                k+=l;
            }
            res^=k;
        }
        if(res)
            printf("Case %d: Alice\n",t++);
        else
            printf("Case %d: Bob\n",t++);
    }
    return 0;
}

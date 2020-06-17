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
#define inf 1000000000
#define eps 1e-9
#define NN 400010

main()
{
    ios_base::sync_with_stdio(false);
    int t,tc;
    //cin>>tc;
    int i,j,k,l,n,m;
    vector<long long>v;
    while(cin>>n>>m)
    {
        __int64 sum,an;
        for(i=0;i<n;i++)
            cin>>k,v.pb(k);
        sort(all(v));
        sum=0;
        an=m;
        for(i=0;i<v.size();i++)
        {
            sum+=v[i]*an;
            if(an>1)
                an--;
        }
        printf("%I64d\n",sum);
        v.clear();
    }
    return 0;
}

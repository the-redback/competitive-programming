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


vector< pair<int,int> >v;

main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t=1,tc;
    //scanf("%d",&tc);
    int i,j,k,l,m,n;
    while(cin>>n>>m)
    {
        v.clear();
        for(i=0;i<n;i++)
        {
            cin>>k;
            v.pb(mp(k,i+1));
        }
        while(v.size()>1)
        {
            if(v[0].first > m)
            {
                v[0].first-=m;
                v.push_back(v[0]);
            }
            v.erase(v.begin());
        }
        printf("%d\n",v[0].second);
    }

    return 0;
}

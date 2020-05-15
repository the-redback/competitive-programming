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
#define NN 100050

vector< pair<int, int> >v;

bool comp(pair<int, int>a,pair<int, int>b)
{
    if(a.first==b.first)
        return a.second<b.second;
    return a.first<b.first;
}

int b[NN];

main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t,tc;
    //cin>>tc;
    int i,j,k,l,m,n;
    while(cin>>n)
    {
        int mx=0;
        v.clear();
        mem(b,0);
        for(i=0;i<n;i++)
        {
            cin>>k>>l;
            v.pb(mp(k,l));
            b[l]++;
            mx=max(mx,l);
        }
        sort(all(v));
        for(i=1;i<=mx;i++)
            b[i]+=b[i-1];
        for(i=0;i<n;i++)
        {
            k=v[i].first;
            l=v[i].second;
            if(b[l-1]>=i+1)
                break;
        }
        if(i!=n)
            puts("Happy Alex");
        else
            puts("Poor Alex");
    }
    return 0;
}

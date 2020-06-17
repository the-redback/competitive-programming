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
#define NN 200010

vector<int>v;
vector<long long>a;

long long rec(long long sum)
{
    sort(a.rbegin(),a.rend());
    for(int i=0;i<a.size();i++)
    {
        sum+=max(a[i],sum);
    }
    return sum;
}

main()
{
    ios_base::sync_with_stdio(false);
    int t,tc;
    //cin>>tc;
    int n,m,q,r,i,j,k,l;
    while(cin>>n>>m)
    {
        v.clear();
        a.clear();
        long long sum=0;
        for(i=0; i<n; i++)
        {
            cin>>k;
            v.pb(k);
            sum+=k;
        }
        for(i=0; i<m; i++)
        {
            cin>>k;
            a.pb(v[k-1]);
            sum-=v[k-1];
            v[k-1]=-1;
        }
        sum=rec(sum);
        cout<<sum<<"\n";
    }
    return 0;
}

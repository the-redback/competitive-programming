/**
 *    @author     : Maruf Tuhin
 *    @School     : CUET CSE 11
 *    @Topcoder   : the_redback
 *    @Codeforces : the_redback
 *    @UVA        : Redback
 *    @link       : http://www.fb.com/maruf.2hin
 */
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
#define inf HUGE_VAL
#define mem(a,b) memset(a,b,sizeof(a))
#define mod 1000000007
map<int,int>mp;
vector<int>v;
main()
{
    char a[50];
    int ret=0;
    int n,i,k,r,s;
    int tc,t=1;
    while(~scanf("%d",&s))
    {
        if(mp.find(s)==mp.end())
        {
            mp[s]=1;
            v.push_back(s);
        }
        else
            mp[s]++;
    }
    for(i=0; i<v.size(); i++)
        printf("%d %d\n",v[i],mp[v[i]]);
    v.clear();
    mp.clear();
    return 0;
}

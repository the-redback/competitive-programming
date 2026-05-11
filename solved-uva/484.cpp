/**
 *                                   ____
 *       ____ ___  ____ ________  __/ __/
 *      / __ `__ \/ __ `/ ___/ / / / /_
 *     / / / / / / /_/ / /  / /_/ / __/
 *    /_/ /_/ /_/\__,_/_/   \__,_/_/
 *
 *    @link : https://the-redback.com
 */
#include <bits/stdc++.h>
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

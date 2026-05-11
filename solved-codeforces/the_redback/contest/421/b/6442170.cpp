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

#define ppb pop_back
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 1000000000
#define eps 1e-9
#define NN 400010
string ss="AHIMOTUVWXY";
string s;

int valid1(void)
{
    int i,j;
    for(i=0;i<s.size();i++)
    {
        int fl=1;
        for(j=0;j<ss.size();j++)
        {
            if(s[i]==ss[j])
            {
                fl=0;
                break;
            }
        }
        if(fl)
            return 0;
    }
    return 1;
}

int valid2(void)
{
    int i=0,j=s.size()-1;
    for(;i<j;i++,j--)
        if(s[i]!=s[j])
            return 0;
    return 1;
}

main()
{
    //ios_base::sync_with_stdio(false);
    int t,tc;
    //cin>>tc;
    int i,j,k,l,n,m;
    while(cin>>s)
    {
        if(valid1())
        {
            if(valid2())
                puts("YES");
            else
                puts("NO");
        }
        else
            puts("NO");
    }
    return 0;
}

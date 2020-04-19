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

main()
{
    //ios_base::sync_with_stdio(false);
    map<string,int>mp;
    string s;
    string ss;
    int ret=0;
    int n,k,l,r,i;
    int tc,t=1;
    scanf("%d",&n);
    scanf("%d",&tc);
    while(n--)
    {
        cin>>s>>k;
        mp[s]=k;
    }
    while(tc--)
    {
        l=0;
        while(cin>>s)
        {
            if(s[0]=='.')
                break;
            if(mp.find(s)!=mp.end())
            {
                l+=mp[s];
            }
        }
        cout<<l<<"\n";
    }
    return 0;
}


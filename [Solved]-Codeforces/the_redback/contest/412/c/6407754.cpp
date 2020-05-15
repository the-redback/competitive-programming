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

vector<string>v;
string s;
char a[100010];

char check(int x)
{
    int i;
    for(i=0;i<v.size();i++)
        if(v[i][x]!='?' && v[i][x]!=a[x])
            return '?';
    return a[x];
}

main()
{
    //ios_base::sync_with_stdio(false);
    int t,tc;
    int i,j,k,l,m,n;
    mem(a,0);
    //cin>>tc;
    while(cin>>n)
    {
        for(j=0;j<n;j++)
        {
            cin>>s;
            for(i=0;i<s.size();i++)
                if(s[i]!='?')
                {
                    a[i]=s[i];
                }
            v.pb(s);
        }
        for(i=0;i<s.size();i++)
        {
            char x=check(i);
            if(x==0)
                a[i]='a';
            else
                a[i]=x;
        }
        puts(a);
    }
    return 0;
}

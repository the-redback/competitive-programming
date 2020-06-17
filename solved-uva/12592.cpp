/**
 *    @author     : Maruf Tuhin
 *    @School     : CUET CSE 11
 *    @Topcoder   : the_redback
 *    @Codeforces : the_redback
 *    @UVA        : Redback
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
#define inf HUGE_VAL
#define mem(a,b) memset(a,b,sizeof(a))

main()
{
    map<string,string>mp;
    string s,ss;
    char a[100];
    char b[100];
    int tc,t=1;
    scanf("%d",&tc);
    getchar();
    while(tc--)
    {
        gets(a);
        gets(b);
        s.assign(a);
        ss.assign(b);
        mp[s]=ss;
    }
    scanf("%d",&tc);
    getchar();
    while(tc--)
    {
        gets(a);
        s.assign(a);
        printf("%s\n",mp[s].c_str());
    }
    return 0;
}
